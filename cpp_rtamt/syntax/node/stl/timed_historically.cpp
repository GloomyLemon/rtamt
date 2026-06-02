#include <node/stl/timed_historically.hpp>

using namespace stl_library;

TimedHistoricallyNode::TimedHistoricallyNode(const PNode& child, const Interval itv) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    interval = itv;
    name = "H[" + std::to_string(interval.getBegin()) + "," + std::to_string(interval.getEnd()) + "](" + child->getName() + ")";

}

