#include <node/arithmetic/abs.hpp>

using namespace stl_library;

AbsNode::AbsNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "abs( " + child->getName() + " )";
}