#include <rtamt_stl_library/stl_log_node.h>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;
using namespace stl_library;

// Initialize previous and current value
StlLogNode::StlLogNode() {
}

void StlLogNode::reset() {
}

double StlLogNode::update(double sample, double base) {
    double out;
    
    out = log(sample)/log(base);

    return out;
}

