#include <node/arithmetic/negate.hpp>

using namespace stl_library;

NegateNode::NegateNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "-( " + child->getName() + " )";
}


