#include <node/arithmetic/exp.hpp>

using namespace stl_library;

ExpNode::ExpNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "exp( " + child->getName() + " )";
}

