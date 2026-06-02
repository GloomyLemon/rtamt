#include <rtamt_stl_library/include/stl_precedes_bounded_node.h>
#include <algorithm>
#include <limits>

#include <boost/circular_buffer.hpp>
#include <abstract_online_operation.hpp>

using namespace stl_library;

struct StlPrecedesBoundedNode::Impl {
    int begin;
    int end;
    int time;

    std::vector<double> prefix_min_hist; // full prefix history
    boost::circular_buffer<double> buffer;

    Impl(int b, int e)
        : begin(b), end(e), time(0),
        buffer(boost::circular_buffer<double>(e + 1))
    {}
};

StlPrecedesBoundedNode::~StlPrecedesBoundedNode() {
    delete impl;
}

StlPrecedesBoundedNode::StlPrecedesBoundedNode(int begin, int end)
    : impl(new Impl(begin, end))
{
    // initialize buffers with neutral values
    for (int i = 0; i <= end; i++) {
        impl->buffer.push_back(-std::numeric_limits<double>::infinity());
    }
}

void StlPrecedesBoundedNode::reset() {
    impl->time = 0;
    impl->prefix_min_hist.clear();

    impl->buffer.clear();

    for (int i = 0; i <= impl->end; i++) {
        impl->buffer.push_back(std::numeric_limits<double>::infinity());
    }
}

#include <iostream>
double StlPrecedesBoundedNode::update(double left, double right) {
    double out;

    impl->buffer.push_back(left);

    out = -std::numeric_limits<double>::infinity();
    double eval_left = -std::numeric_limits<double>::infinity();
    double eval_right = right;

    int start = 0;
    int stop = impl->end - impl->begin;
    for (int i = start; i <= stop; ++i) {
        eval_left = std::max(eval_left, impl->buffer[i]);
    }


    out = std::max(out, std::min(eval_left, eval_right));
    return out;
}
