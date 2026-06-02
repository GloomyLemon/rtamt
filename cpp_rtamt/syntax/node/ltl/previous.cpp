#include <node/ltl/previous.hpp>

using namespace stl_library;

PreviousNode::PreviousNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "P( " + child->getName() + " )";
}



