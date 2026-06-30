#include <rtamt_stl_library/include/stl_precedes_bounded_node.h>
#include <algorithm>
#include <limits>
#include <deque>

using namespace stl_library;

// Initialize previous and current value

struct StlPrecedesBoundedNode::Impl {
    int begin;
    int end;
    int window_size0;
    int window_size1;
    std::deque<double> buffer0;
    std::deque<double> buffer1;

    Impl(int b, int e)
        : begin(b), end(e), window_size0(2 * end - begin + 1), window_size1(end + 1), buffer0(window_size0), buffer1(window_size1) {}


};

StlPrecedesBoundedNode::~StlPrecedesBoundedNode() {
    delete impl;
}

StlPrecedesBoundedNode::StlPrecedesBoundedNode(int begin, int end): impl(new Impl(begin, end)) {
    reset();
}

void StlPrecedesBoundedNode::reset() {
    int i;
    for (i = 0; i <= impl->window_size0; i++) {
        double s_left;
        s_left = std::numeric_limits<double>::infinity();
        impl->buffer0.push_back(s_left);
        impl->buffer0.pop_front();
    }
    for (i = 0; i <= impl->window_size1; i++) {
        double s_right;
        s_right = -std::numeric_limits<double>::infinity();
        impl->buffer1.push_back(s_right);
        impl->buffer1.pop_front();
    }
}


double StlPrecedesBoundedNode::update(double p_left, double p_right) {
    double out;

    impl->buffer0.push_back(p_left);
    impl->buffer0.pop_front();
    impl->buffer1.push_back(p_right);
    impl->buffer1.pop_front();

    out = -std::numeric_limits<double>::infinity();
    int i;
    for (i = 0; i <= impl->end - impl->begin; i++) {
        double left;
        double right;
        right = impl->buffer1.at(impl->window_size1 - 1 - i);
        left = std::numeric_limits<double>::infinity();
        for (int j = 0; j <= impl->end; j++) {
            int idx = impl->window_size0 - 1 - i - j;
            if (idx < 0) break;
            left = std::min(left, impl->buffer0.at(idx));
        }
        out = std::max(out, std::min(left, right));
    }
    return out;
}