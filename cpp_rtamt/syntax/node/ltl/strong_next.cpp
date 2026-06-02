#include <node/ltl/strong_next.hpp>

using namespace stl_library;

StrongNextNode::StrongNextNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "strongX( " + child->getName() + " )";
}

