#include <node/arithmetic/sqrt.hpp>

using namespace stl_library;

SqrtNode::SqrtNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "sqrt( " + child->getName() + " )";
}