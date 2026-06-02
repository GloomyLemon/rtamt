#include <rtamt_stl_library/include/stl_constant_node.h>
#include <algorithm>
#include <limits>

using namespace stl_library;

// Initialize previous and current value
StlConstantNode::StlConstantNode(double val) {
    this->val = val;
}

StlConstantNode::StlConstantNode(): StlConstantNode(0) {}



void StlConstantNode::reset() {
}

double StlConstantNode::update(double lsample, double rsample) {
    return this->val;
}

