#include <node/ltl/historically.hpp>

using namespace stl_library;

HistoricallyNode::HistoricallyNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "H( " + child->getName() + " )";
}
