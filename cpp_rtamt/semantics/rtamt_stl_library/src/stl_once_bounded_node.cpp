#include <rtamt_stl_library/include/stl_once_bounded_node.h>
#include <algorithm>
#include <limits>

#include <boost/circular_buffer.hpp>
#include <abstract_online_operation.hpp>

using namespace stl_library;


struct StlOnceBoundedNode::Impl {
    int begin;
    int end;
    boost::circular_buffer<double> buffer;

    Impl(int b, int e)
        : begin(b), end(e), buffer(end + 1) {}
};

StlOnceBoundedNode::~StlOnceBoundedNode() {
    delete impl;
}

// Initialize previous and current value
StlOnceBoundedNode::StlOnceBoundedNode(int begin, int end) : impl(new Impl(begin, end)) {
    
    int i;
    for(i=0; i <= impl->end; i++) {
        double s;
        s = - std::numeric_limits<double>::infinity();
        impl->buffer.push_back(s);
    }
}

void StlOnceBoundedNode::reset() {
    int i;
    for(i=0; i <= impl->end; i++) {
        double s;
        s = - std::numeric_limits<double>::infinity();
        impl->buffer.push_back(s);
    }
}

double StlOnceBoundedNode::update(double sample, double unused) {
    double out;

    impl->buffer.push_back(sample);
    
    out = - std::numeric_limits<double>::infinity();
    int i;
    for (i=0; i <= impl->end - impl->begin; i++) {
        out = std::max(out, impl->buffer[i]);
    }
    return out;
}