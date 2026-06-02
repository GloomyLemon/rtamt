#include <node/ltl/always.hpp>

using namespace stl_library;

AlwaysNode::AlwaysNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "G( " + child->getName() + " )";
}





