#include <node/arithmetic/ln.hpp>

using namespace stl_library;

LnNode::LnNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "ln( " + child->getName() + " )";
}
