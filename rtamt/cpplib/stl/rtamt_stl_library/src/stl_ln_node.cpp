#include <rtamt_stl_library/stl_ln_node.h>
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

double StlLnNode::update(double sample) {
    double out;
    
    out = log(sample);

    return out;
}

