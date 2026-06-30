#ifndef STL_INTERVAL_H
#define STL_INTERVAL_H

#include<String>
#include<vector>
#include<memory>

namespace stl_library {


    class Interval {
    private:
        double begin;
        double end;
        std::string begin_unit;
        std::string end_unit;

    public:
        Interval();
        Interval(const double begin, const double end, const std::string begin_unit = "s", const std::string end_unit = "s");
        double getBegin() { return begin; }
        double getEnd() { return end; }
        std::string getBeginUnit() { return begin_unit; }
        std::string getEndUnit() { return end_unit; }


    };
}

#endif
