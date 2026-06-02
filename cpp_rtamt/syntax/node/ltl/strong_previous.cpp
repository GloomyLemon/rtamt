#include <node/ltl/strong_previous.hpp>

using namespace stl_library;

StrongPreviousNode::StrongPreviousNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "strongP( " + child->getName() + " )";
}




