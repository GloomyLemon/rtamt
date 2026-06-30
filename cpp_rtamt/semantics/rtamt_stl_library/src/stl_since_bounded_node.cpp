#include <rtamt_stl_library/include/stl_since_bounded_node.h>
#include <algorithm>
#include <limits>

#include <deque>
#include <abstract_online_operation.hpp>

using namespace stl_library;


struct StlSinceBoundedNode::Impl {
    int begin;
    int end;
    int window_size;
    std::deque<double> buffer0;
    std::deque<double> buffer1;

    Impl(int b, int e)
        : begin(b), end(e), window_size(e+1), buffer0(window_size), buffer1(window_size)
    {}
};

StlSinceBoundedNode::~StlSinceBoundedNode() {
    delete impl;
}

// Initialize previous and current value
StlSinceBoundedNode::StlSinceBoundedNode(int begin, int end) : impl(new Impl(begin, end)) {
    reset();
}

void StlSinceBoundedNode::reset() {
    int i;
    for(i=0; i <= impl->end; i++) {
        double s_left;
        double s_right;
        s_left = std::numeric_limits<double>::infinity();
        s_right = - std::numeric_limits<double>::infinity();
        impl->buffer0.push_back(s_left);
        impl->buffer0.pop_front();
        impl->buffer1.push_back(s_right);
        impl->buffer1.pop_front();
    }
}

double StlSinceBoundedNode::update(double p_left, double p_right) {
    double out;

    impl->buffer0.push_back(p_left);
    impl->buffer0.pop_front();
    impl->buffer1.push_back(p_right);
    impl->buffer1.pop_front();
    
    out = - std::numeric_limits<double>::infinity();
    for (int i=impl->begin; i <= impl->end; i++) {
        double left; 
        double right;
        right = impl->buffer1.at(impl->window_size - 1 - i);
        left = std::numeric_limits<double>::infinity();
        for (int j= impl->window_size - i; j < impl->window_size; j++) {
            left = std::min(left, impl->buffer0.at(j));
        }
        out = std::max(out, std::min(left, right));
    }
    return out;
}