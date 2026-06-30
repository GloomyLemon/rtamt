#include <interval/interval.hpp>

using namespace stl_library;

Interval::Interval() {
    this->begin = 0;
    this->end = 0;
    this->begin_unit = "s";
    this->end_unit = "s";
}

Interval::Interval(const double begin, const double end, const std::string begin_unit, const std::string end_unit) {
    this->begin = begin;
    this->end = end;
    this->begin_unit = begin_unit;
    this->end_unit = end_unit;
}
