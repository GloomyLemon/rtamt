#include <node/ltl/eventually.hpp>

using namespace stl_library;

EventuallyNode::EventuallyNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "F( " + child->getName() + " )";
}
