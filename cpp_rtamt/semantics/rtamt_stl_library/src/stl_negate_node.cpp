#include <rtamt_stl_library/include/stl_negate_node.h>
#include <algorithm>
#include <limits>

using namespace std;
using namespace stl_library;

// Initialize previous and current value
StlNegateNode::StlNegateNode() {
}

void StlNegateNode::reset() {
}

double StlNegateNode::update(double sample, double unused) {
    double out;
    
    out = -sample;

    return out;
}
