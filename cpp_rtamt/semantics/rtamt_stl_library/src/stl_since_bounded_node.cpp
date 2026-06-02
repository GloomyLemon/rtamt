#include <rtamt_stl_library/include/stl_since_bounded_node.h>
#include <algorithm>
#include <limits>

#include <boost/circular_buffer.hpp>
#include <abstract_online_operation.hpp>

using namespace stl_library;


struct StlSinceBoundedNode::Impl {
    int begin;
    int end;
    boost::circular_buffer<double> buffer[2];

    Impl(int b, int e)
        : begin(b), end(e), buffer{ boost::circular_buffer<double>(e + 1), boost::circular_buffer<double>(e + 1) }
    {}
};

StlSinceBoundedNode::~StlSinceBoundedNode() {
    delete impl;
}

// Initialize previous and current value
StlSinceBoundedNode::StlSinceBoundedNode(int begin, int end) : impl(new Impl(begin, end)) {
    
    int i;
    for(i=0; i <= end; i++) {
        double s_left;
        double s_right;
        s_left = std::numeric_limits<double>::infinity();
        s_right = - std::numeric_limits<double>::infinity();
        impl->buffer[0].push_back(s_left);
        impl->buffer[1].push_back(s_right);
    }
}

void StlSinceBoundedNode::reset() {
    int i;
    for(i=0; i <= impl->end; i++) {
        double s_left;
        double s_right;
        s_left = std::numeric_limits<double>::infinity();
        s_right = - std::numeric_limits<double>::infinity();
        impl->buffer[0].push_back(s_left);
        impl->buffer[1].push_back(s_right);
    }
}

double StlSinceBoundedNode::update(double left, double right) {
    double out;

    impl->buffer[0].push_back(left);
    impl->buffer[1].push_back(right);
    
    out = - std::numeric_limits<double>::infinity();
    int i;
    for (i=0; i <= impl->end - impl->begin; i++) {
        double left; 
        double right;
        right = impl->buffer[1][i];
        left = std::numeric_limits<double>::infinity();
        int j;
        for(j=i + 1; j <= impl->end; j++) {
            left = std::min(left, impl->buffer[0][j]);
        }
        out = std::max(out, std::min(left, right));
    }
    return out;
}