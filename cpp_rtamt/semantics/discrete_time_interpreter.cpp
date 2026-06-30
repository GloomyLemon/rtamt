#include <discrete_time_interpreter.hpp>

#include <interval/interval.hpp>

#include <cmath>
#include <iostream>

using namespace stl_library;

AbstractDiscreteTimeInterpreter::AbstractDiscreteTimeInterpreter() {
    set_sampling_period(1.0, "s", 0.1);
}

double AbstractDiscreteTimeInterpreter::get_sampling_frequency() {
    return 1 / get_sampling_period();
}

double AbstractDiscreteTimeInterpreter::scale_time(double timestamp) {
    return timestamp * units[sampling_period_unit];
}

double AbstractDiscreteTimeInterpreter::get_sampling_period() {
    //std::cout << sampling_period << " " << sampling_period_unit << " = " << sampling_period * units[sampling_period_unit] << "\n";
    return sampling_period * units[sampling_period_unit];
}

std::string AbstractDiscreteTimeInterpreter::get_sampling_unit() {
    return sampling_period_unit;
}

int AbstractDiscreteTimeInterpreter::get_violation_count() {
    return sampling_violation_counter;
}

void AbstractDiscreteTimeInterpreter::set_sampling_period(double p_period, std::string p_unit, double p_tolerance) {
    sampling_period = p_period;
    sampling_period_unit = p_unit;
    sampling_tolerance = p_tolerance;
}

bool AbstractDiscreteTimeInterpreter::dataset_check(const DataSet& p_dataset) {
    return true;
}

void AbstractDiscreteTimeInterpreter::update_sampling_violation_counter(double duration) {
    double tolerance = get_sampling_period() * sampling_tolerance;
    double lower_bound = get_sampling_period() - tolerance;
    double upper_bound = get_sampling_period() + tolerance;

    if (duration < lower_bound || duration > upper_bound) {
        sampling_violation_counter += 1;
    }
}