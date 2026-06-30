#include <rtamt_stl_library/include/stl_historically_bounded_node.h>
#include <limits>
#include <deque>

using namespace stl_library;



struct StlHistoricallyBoundedNode::Impl{
    int begin;
    int end;
    int window_size;
    std::deque<double> buffer;

    Impl(int b, int e)
        : begin(b), end(e), window_size(end + 1), buffer(window_size) {}
};

StlHistoricallyBoundedNode::~StlHistoricallyBoundedNode() {
    delete impl;
}


// Initialize previous and current value
StlHistoricallyBoundedNode::StlHistoricallyBoundedNode(int begin, int end) : impl(new Impl(begin, end)) {
    reset();
}

void StlHistoricallyBoundedNode::reset() {

    for(int i=0; i <= impl->end; i++) {
        double s;
        s = std::numeric_limits<double>::infinity();
        impl->buffer.push_back(s);
        impl->buffer.pop_front();
    }
}

double StlHistoricallyBoundedNode::update(double sample, double rsample) {
    double out;


    impl->buffer.push_back(sample);
    impl->buffer.pop_front();

    out = std::numeric_limits<double>::infinity();
    for (int i = impl->begin; i <= impl->end; i++) {
        out = std::min(out, impl->buffer.at(impl->buffer.size() - 1 - i));
    }
    return out;
}