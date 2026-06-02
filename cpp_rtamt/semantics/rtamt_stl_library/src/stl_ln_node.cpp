#include <rtamt_stl_library/include/stl_ln_node.h>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;
using namespace stl_library;

// Initialize previous and current value
StlLnNode::StlLnNode() {
}

void StlLnNode::reset() {
}

double StlLnNode::update(double sample, double unused) {
    double out;

    if (sample <= 0.0) {
        out = -std::numeric_limits<double>::infinity();
    }
    else {
        out = std::log(sample);
    }

    return sanitize(out);

}

