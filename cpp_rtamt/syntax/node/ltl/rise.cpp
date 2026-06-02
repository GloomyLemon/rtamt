#include <node/ltl/rise.hpp>

using namespace stl_library;

RiseNode::RiseNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "rise( " + child->getName() + " )";
}





