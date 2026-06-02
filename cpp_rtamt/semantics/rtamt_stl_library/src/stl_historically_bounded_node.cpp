#include <rtamt_stl_library/include/stl_historically_bounded_node.h>
#include <algorithm>
#include <limits>

#include <boost/circular_buffer.hpp>
#include <boost/circular_buffer/base.hpp>

using namespace stl_library;



struct StlHistoricallyBoundedNode::Impl{
    int begin;
    int end;
    boost::circular_buffer<double> buffer;

    Impl(int b, int e)
        : begin(b), end(e), buffer(end+1) {}
};

StlHistoricallyBoundedNode::~StlHistoricallyBoundedNode() {
    delete impl;
}


// Initialize previous and current value
StlHistoricallyBoundedNode::StlHistoricallyBoundedNode(int begin, int end) : impl(new Impl(begin, end)) {
    
    int i;
    for(i=0; i <= impl->end; i++) {
        double s;
        s = std::numeric_limits<double>::infinity();
        impl->buffer.push_back(s);
    }
}

void StlHistoricallyBoundedNode::reset() {

    int i;
    for(i=0; i <= impl->end; i++) {
        double s;
        s = std::numeric_limits<double>::infinity();
        impl->buffer.push_back(s);
    }
}

double StlHistoricallyBoundedNode::update(double sample, double rsample) {
    double out;


    impl->buffer.push_back(sample);
    out = std::numeric_limits<double>::infinity();
    int i;
    for (i=0; i <= impl->end - impl->begin; i++) {
        out = std::min(out, impl->buffer[i]);
    }
    return out;
}