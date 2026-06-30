#include <rtamt_stl_library/include/stl_once_bounded_node.h>
#include <algorithm>
#include <limits>
#include <deque>

#include <abstract_online_operation.hpp>

using namespace stl_library;


struct StlOnceBoundedNode::Impl {
    int begin;
    int end;
    size_t window_size;
    std::deque<double> buffer;

    Impl(int b, int e)
        : begin(b), end(e), window_size(end + 1), buffer(window_size) {
    }
};

StlOnceBoundedNode::~StlOnceBoundedNode() {
    delete impl;
}

// Initialize previous and current value
StlOnceBoundedNode::StlOnceBoundedNode(int begin, int end) : impl(new Impl(begin, end)) {
    reset();
}

void StlOnceBoundedNode::reset() {
    int i;
    for(i=0; i <= impl->end; i++) {
        double s;
        s = - std::numeric_limits<double>::infinity();
        impl->buffer.push_back(s);
        impl->buffer.pop_front();
    }
}

double StlOnceBoundedNode::update(double sample, double unused) {
    double out = -std::numeric_limits<double>::infinity();

    impl->buffer.push_back(sample);
    impl->buffer.pop_front();

    for (int i = impl->begin; i <= impl->end; i++) {
        out = std::max(out, impl->buffer.at(impl->buffer.size() - 1 - i));
    }

            //int size = impl->buffer.size();
            //out = -std::numeric_limits<double>::infinity();

            //for (int i = impl->begin; i <= impl->end; i++) {
            //    int idx = size - 1 - i;
            //    out = std::max(out, impl->buffer[idx]);
            //}

    return out;
}