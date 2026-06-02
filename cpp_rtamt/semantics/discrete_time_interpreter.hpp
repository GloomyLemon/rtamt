#pragma once

#include <utility>
#include <string>
#include <map>
#include <time_interpreter.hpp>
#include <node/abstract_node.hpp>
#include <interval/interval.hpp>

namespace stl_library {

    class AbstractDiscreteTimeInterpreter : public AbstractTimeInterpreter {
    private:
        double sampling_period;
        double sampling_tolerance;
        std::string sampling_period_unit;
        int sampling_violation_counter;

        std::map<std::string, double> units { 
            {"s", 10000000.0},
            {"ms", 1000000.0},
            {"us", 1000.0},
            {"ns", 1.0}
        };


    public:
        AbstractDiscreteTimeInterpreter();
        void set_sampling_period(double p_period, std::string p_unit, double p_tolerance);
        double get_sampling_period();
        double get_sampling_frequency();
        int get_violation_count();
        bool dataset_check(const DataSet& p_dataset);
        void update_sampling_violation_counter(double duration);
        std::pair<int, int>  time_unit_transformer(Interval &itv);
    };

}