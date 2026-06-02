#include <node/ltl/fall.hpp>

using namespace stl_library;

FallNode::FallNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "fall( " + child->getName() + " )";
}

