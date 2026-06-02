#include <node/ltl/next.hpp>

using namespace stl_library;

NextNode::NextNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "X( " + child->getName() + " )";
}
