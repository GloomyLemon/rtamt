#include <node/ltl/once.hpp>

using namespace stl_library;

OnceNode::OnceNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "O( " + child->getName() + " )";
}



