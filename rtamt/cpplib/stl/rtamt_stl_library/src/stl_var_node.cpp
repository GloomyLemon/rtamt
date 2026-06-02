#include <rtamt_stl_library/stl_var_node.h>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;
using namespace stl_library;

// Initialize previous and current value
StlVarNode::StlVarNode() {
}

void StlVarNode::reset() {
}

double StlVarNode::update(double sample) {
    double out;
    
    out = sample;

    return out;
}

