// Multi-file CSV loader with prefixed keys, merging,
// timestamp normalization to t=0, downsampling with quantized bucket edges,
// and real-time 1 Hz printing.
// ------------------------------------------------------------
// Fully C++14 compatible and ready for Visual Studio.
// ------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <thread>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <functional>

#ifdef _WIN32
#include <direct.h>  // _getcwd
#else
#include <unistd.h>  // getcwd
#endif

#include <node/abstract_node.hpp>
#include <node/arithmetic/addition.hpp>
#include <node/arithmetic/division.hpp>
#include <node/arithmetic/subtraction.hpp>
#include <node/arithmetic/ln.hpp>
#include <node/arithmetic/negate.hpp>
#include <node/ltl/constant.hpp>
#include <node/ltl/variable.hpp>
#include <node/ltl/disjunction.hpp>
#include <abstract_discrete_time_online_interpreter.hpp>

using namespace stl_library;

// ---------- BASIC TYPES ----------
typedef std::map<std::string, double> DataSet;
typedef std::map<double, DataSet>     TimeSeries;

// ---------- SETTINGS ----------
static const double   DOWNSAMPLE_INTERVAL_SEC = 1.0;   // keep latest sample per X seconds
static const size_t   PRINT_COLUMN_LIMIT = 200;   // cap summary printing
static const size_t   PRINT_RT_MAX_FIELDS = 12;    // max fields printed per real-time line

// ------------------------------------------------------------
// Get working directory (useful in Visual Studio)
// ------------------------------------------------------------
std::string getWorkingDirectory()
{
    char buffer[FILENAME_MAX];
#ifdef _WIN32
    _getcwd(buffer, FILENAME_MAX);
#else
    getcwd(buffer, FILENAME_MAX);
#endif
    return std::string(buffer);
}

// ------------------------------------------------------------
// Convert string -> double safely
// ------------------------------------------------------------
bool toDouble(const std::string& s, double& out)
{
    try {
        size_t idx = 0;
        out = std::stod(s, &idx);
        return idx > 0;
    }
    catch (...) {
        return false;
    }
}

// ------------------------------------------------------------
// Load a single CSV file:
//  • prefix column names (except LocalTime)
//  • merge into provided TimeSeries
// ------------------------------------------------------------
void loadCSVWithPrefix(const std::string& filename,
    const std::string& prefix,
    std::set<std::string>& uniqueColumnNames,
    std::size_t& totalRows,
    TimeSeries& mergedSeries)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "ERROR: Could not open file: " << filename << "\n";
        std::cerr << "Looking in:\n  " << getWorkingDirectory() << "\n\n";
        return;
    }

    std::string line;
    std::vector<std::string> columns;

    // ---- Read header ----
    if (!std::getline(file, line)) {
        std::cerr << "ERROR: Empty file: " << filename << "\n";
        return;
    }

    {
        std::stringstream header(line);
        std::string col;
        while (std::getline(header, col, ',')) {
            columns.push_back(col);
        }
    }

    // Find LocalTime column
    int timeIndex = -1;
    for (std::size_t i = 0; i < columns.size(); ++i) {
        if (columns[i] == "LocalTime") {
            timeIndex = (int)i;
            break;
        }
    }
    if (timeIndex < 0) {
        std::cerr << "ERROR: LocalTime missing in " << filename << "\n";
        return;
    }

    // Add unique prefixed keys (once per file)
    for (std::size_t i = 0; i < columns.size(); ++i) {
        if ((int)i == timeIndex) continue;
        uniqueColumnNames.insert(prefix + "_" + columns[i]);
    }

    // ---- Read data rows ----
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream row(line);
        std::vector<std::string> values;
        std::string cell;

        while (std::getline(row, cell, ',')) {
            values.push_back(cell);
        }

        if (values.size() != columns.size()) continue;

        double t = 0.0;
        if (!toDouble(values[timeIndex], t)) continue;

        DataSet& entry = mergedSeries[t];

        for (std::size_t i = 0; i < columns.size(); ++i) {
            if ((int)i == timeIndex) continue;

            double value;
            if (!toDouble(values[i], value)) continue;

            entry[prefix + "_" + columns[i]] = value;
        }

        ++totalRows;
    }
}

// ------------------------------------------------------------
// Normalize timestamps so the first timestamp becomes t = 0
// ------------------------------------------------------------
void normalizeTimestamps(TimeSeries& ts)
{
    if (ts.empty()) return;

    double t0 = ts.begin()->first;
    TimeSeries normalized;

    for (TimeSeries::const_iterator it = ts.begin(); it != ts.end(); ++it) {
        double t = it->first - t0;
        normalized[t] = it->second;
    }

    ts.swap(normalized);
}

// ------------------------------------------------------------
// Downsample: keep the *latest* sample within each interval,
// and store it under the quantized bucket time k*interval.
// This guarantees timestamps: 0, 1, 2, ...
// ------------------------------------------------------------
TimeSeries downsampleKeepLatestQuantized(const TimeSeries& input, double interval)
{
    TimeSeries out;
    if (input.empty() || interval <= 0.0) return out;

    const double EPS = 1e-12;
    long long lastBucket = -1;
    DataSet running; // running state that accumulates latest values for all keys

    for (TimeSeries::const_iterator it = input.begin(); it != input.end(); ++it)
    {
        const double t = it->first;
        const long long bucket = static_cast<long long>(std::floor((t + EPS) / interval));

        // incorporate this sample into the running state (update latest values)
        for (const auto &kv : it->second) {
            running[kv.first] = kv.second;
        }

        if (lastBucket == -1) {
            // first seen bucket
            lastBucket = bucket;
            continue;
        }

        if (bucket == lastBucket) {
            // still in same bucket: keep accumulating
            continue;
        }

        // bucket changed: flush the running state for lastBucket
        const double quantizedT = static_cast<double>(lastBucket) * interval;
        out[quantizedT] = running;

        // fill any empty intermediate buckets with the same running state (carry-forward)
        for (long long b = lastBucket + 1; b < bucket; ++b) {
            out[static_cast<double>(b) * interval] = running;
        }

        // start tracking the new bucket (running already includes current sample)
        lastBucket = bucket;
    }

    // flush final bucket
    if (lastBucket != -1) {
        out[static_cast<double>(lastBucket) * interval] = running;
    }

    return out;
}

// ------------------------------------------------------------
// Print one timestamp per second (real-time simulation)
// ------------------------------------------------------------
void printRealtime(const TimeSeries& ts, std::size_t maxFields)
{
    if (ts.empty()) {
        std::cout << "[RT] No data.\n";
        return;
    }

    std::cout << "\n[RT] Starting real-time 1 Hz output...\n";

    for (TimeSeries::const_iterator it = ts.begin(); it != ts.end(); ++it)
    {
        std::ostringstream line;
        line << "t=" << std::fixed << std::setprecision(6) << it->first;

        const DataSet& ds = it->second;

        std::size_t printed = 0;
        for (DataSet::const_iterator kv = ds.begin();
            kv != ds.end() && printed < maxFields;
            ++kv, ++printed)
        {
            line << "  " << kv->first << "=" << kv->second;
        }

        if (ds.size() > maxFields) {
            line << "  ...(" << (ds.size() - maxFields) << " more)";
        }

        std::cout << line.str() << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "[RT] End of stream.\n";
}

// ------------------------------------------------------------
// MAIN
// ------------------------------------------------------------
int main()
{
    // The files to load
    const std::string files[] = {
        "PFM1_HAI1.csv",
        "PFM1_HAI2.csv",
        "PFM1_HAI3.csv",
        "PFM1_HAI4.csv",
        "PFM1_BeltHeating.csv"
    };

    const std::string prefixes[] = {
        "PFM1_HAI1",
        "PFM1_HAI2",
        "PFM1_HAI3",
        "PFM1_HAI4",
        "PFM1_BeltHeating"
    };

    const std::size_t fileCount = sizeof(files) / sizeof(files[0]);

    std::cout << "Working directory:\n  " << getWorkingDirectory() << "\n\n";

    TimeSeries merged;
    std::set<std::string> uniqueColumns;
    std::size_t totalRows = 0;

    // ---- Load all files ----
    for (std::size_t i = 0; i < fileCount; ++i) {
        loadCSVWithPrefix(files[i], prefixes[i], uniqueColumns, totalRows, merged);
    }

    // ---- Summary before normalization ----
    std::cout << "Merged CSV Summary:\n";
    std::cout << "  Files read          : " << fileCount << "\n";
    std::cout << "  Total rows merged   : " << totalRows << "\n";
    std::cout << "  Unique timestamps   : " << merged.size() << "\n";

    if (!merged.empty()) {
        std::cout << "  Raw first timestamp : " << merged.begin()->first << "\n";
        std::cout << "  Raw last timestamp  : " << merged.rbegin()->first << "\n";
    }

    // ---- Normalize timestamps so t=0 ----
    normalizeTimestamps(merged);

    if (!merged.empty()) {
        std::cout << "\nTimestamps normalized:\n";
        std::cout << "  New first timestamp : " << merged.begin()->first << "\n";
        std::cout << "  New last timestamp  : " << merged.rbegin()->first << "\n";
    }

    //// ---- Print some columns ----
    //std::cout << "\nColumn names (up to " << PRINT_COLUMN_LIMIT << "):\n";
    //std::size_t count = 0;
    //for (std::set<std::string>::const_iterator it = uniqueColumns.begin();
    //    it != uniqueColumns.end() && count < PRINT_COLUMN_LIMIT;
    //    ++it, ++count)
    //{
    //    std::cout << "  - " << *it << "\n";
    //}
    //if (uniqueColumns.size() > PRINT_COLUMN_LIMIT) {
    //    std::cout << "  ... (" << (uniqueColumns.size() - PRINT_COLUMN_LIMIT) << " more)\n";
    //}

    // ---- Downsample with quantized bucket edges ----
    TimeSeries down = downsampleKeepLatestQuantized(merged, DOWNSAMPLE_INTERVAL_SEC);

    std::cout << "\nDownsampled (quantized to bucket edges):\n";
    std::cout << "  Interval seconds     : " << DOWNSAMPLE_INTERVAL_SEC << "\n";
    std::cout << "  Timestamps kept      : " << down.size() << "\n";
    if (!down.empty()) {
        std::cout << "  First downsampled t  : " << down.begin()->first << "\n";
        std::cout << "  Last downsampled t   : " << down.rbegin()->first << "\n";
    }



	// ---- STL formula ----
    PNode v1 = std::make_shared<VariableNode>("PFM1_HAI1_outputEstimatedNozzleTemperature");
    PNode v2 = std::make_shared<VariableNode>("PFM1_HAI2_outputEstimatedNozzleTemperature");
    PNode v3 = std::make_shared<VariableNode>("PFM1_HAI3_outputEstimatedNozzleTemperature");
    PNode v4 = std::make_shared<VariableNode>("PFM1_HAI4_outputEstimatedNozzleTemperature");
    PNode s12 = std::make_shared<AdditionNode>(v1, v2); 
    PNode s34 = std::make_shared<AdditionNode>(v3, v4);
    PNode sum = std::make_shared<AdditionNode>(s12, s34);
    PNode four = std::make_shared<ConstantNode>(4.0);
    PNode avg = std::make_shared<DivisionNode>(sum, four);

    // HTValueRaw = - ln((0.5 or (PFM1_BeltHeating__BELTTEMPSE10 / 10 - THeatSource)) /
    //                 (0.5 or (PFM1_BeltHeating__BELTTEMPSE4  / 10 - THeatSource))) / 0.0029821909;

    PNode bt10 = std::make_shared<VariableNode>("PFM1_BeltHeating_BELTTEMPSE10");
    PNode bt4  = std::make_shared<VariableNode>("PFM1_BeltHeating_BELTTEMPSE4");

    PNode div_bt10_10 = std::make_shared<DivisionNode>(bt10, std::make_shared<ConstantNode>(10.0));
    PNode div_bt4_10  = std::make_shared<DivisionNode>(bt4,  std::make_shared<ConstantNode>(10.0));

    PNode sub_bt10 = std::make_shared<SubtractionNode>(div_bt10_10, avg);
    PNode sub_bt4  = std::make_shared<SubtractionNode>(div_bt4_10,  avg);

    PNode half = std::make_shared<ConstantNode>(0.5);

    PNode or_num = std::make_shared<DisjunctionNode>(half, sub_bt10);
    PNode or_den = std::make_shared<DisjunctionNode>(half, sub_bt4);

    PNode ratio = std::make_shared<DivisionNode>(or_num, or_den);
    PNode lnnd  = std::make_shared<LnNode>(ratio);
    PNode negln = std::make_shared<NegateNode>(lnnd);

    PNode denom_const = std::make_shared<ConstantNode>(0.0029821909);
    PNode HTValueRaw = std::make_shared<DivisionNode>(negln, denom_const);

    // --- Filter merged and down to keep only variables used by the constructed ASTs ---
    std::set<std::string> usedVars;

    std::function<void(const PNode&)> collectVars = [&](const PNode& node) {
        if (!node) return;
        for (const auto& v : node->getInVars()) usedVars.insert(v);
        for (const auto& v : node->getOutVars()) usedVars.insert(v);
        for (const auto& c : node->getChildren()) collectVars(c);
    };

    // collect from both avg (THeatSource) and HTValueRaw
    collectVars(avg);
    collectVars(HTValueRaw);

    // Print which columns/variables will be kept
    std::cout << "\nColumns to keep (" << usedVars.size() << "):\n";
    for (const auto &name : usedVars) {
        std::cout << "  - " << name << "\n";
    }

    // Helper to filter a TimeSeries in-place
    auto filterTimeSeries = [&](TimeSeries& ts) {
        for (auto it = ts.begin(); it != ts.end(); ++it) {
            DataSet& ds = it->second;
            std::vector<std::string> toErase;
            for (const auto& kv : ds) {
                if (usedVars.find(kv.first) == usedVars.end())
                    toErase.push_back(kv.first);
                //else std::cout << "Keeping " + kv.first + "\n";
            }
            for (const auto& k : toErase) ds.erase(k);
        }
    };

    filterTimeSeries(merged);
    filterTimeSeries(down);

    //// Update uniqueColumns to reflect kept variables
    //std::set<std::string> filteredColumns;
    //for (const auto& name : uniqueColumns) if (usedVars.find(name) != usedVars.end()) filteredColumns.insert(name);
    //uniqueColumns.swap(filteredColumns);

    // ---- Real-time play-out ----
    // Instantiate discrete-time online interpreter with HTValueRaw as root
    DiscreteTimeOnlineInterpreter I(HTValueRaw);
    I.set_ast(HTValueRaw);

    std::cout << "\n-- Online interpretation (feeding samples one-by-one) --\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    long long total_update_us = 0;
    std::size_t update_count = 0;

    for (TimeSeries::const_iterator it = down.begin(); it != down.end(); ++it) {
        double timestamp = it->first;
        DataSet dataset = it->second; // copy into expected parameter

        auto t_start = std::chrono::high_resolution_clock::now();
        double result = I.update(timestamp, dataset);
        auto t_end = std::chrono::high_resolution_clock::now();

        auto dur_us = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start).count();
        total_update_us += dur_us;
        ++update_count;

        //std::cout << "t=" << std::fixed << std::setprecision(6) << timestamp
        //          << "  HTValueRaw=" << result
        //          << "  (update_time=" << dur_us << " us)" << "\n";
    }

    std::cout << "\n-- Done online interpretation --\n";
    std::this_thread::sleep_for(std::chrono::seconds(4));

    // Print timing summary
    if (update_count > 0) {
        double total_ms = static_cast<double>(total_update_us) / 1000.0;
        double avg_us = static_cast<double>(total_update_us) / static_cast<double>(update_count);
        double avg_ms = avg_us / 1000.0;
        std::cout << "\nUpdate timing summary: total=" << total_ms << " ms over " << update_count
                  << " updates. average=" << avg_us << " us (" << avg_ms << " ms)\n";
    }

    //// Also print realtime stream as before
    //printRealtime(down, PRINT_RT_MAX_FIELDS);



    return 0;
}