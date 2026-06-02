#include <node/ltl/neg.hpp>

using namespace stl_library;

NotNode::NotNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "!( " + child->getName() + " )";
}
