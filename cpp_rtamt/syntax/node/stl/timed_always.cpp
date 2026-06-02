#include <node/stl/timed_always.hpp>

using namespace stl_library;

TimedAlwaysNode::TimedAlwaysNode(const PNode& child, const Interval itv) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    interval = itv;
    name = "G[" + std::to_string(interval.getBegin()) + "," + std::to_string(interval.getEnd()) + "](" + child->getName() + ")";

}
