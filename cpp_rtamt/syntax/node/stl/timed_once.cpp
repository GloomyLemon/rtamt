#include <node/stl/timed_once.hpp>

using namespace stl_library;

TimedOnceNode::TimedOnceNode(const PNode& child, const Interval itv) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    interval = itv;
    name = "O[" + std::to_string(interval.getBegin()) + "," + std::to_string(interval.getEnd()) + "](" + child->getName() + ")";

}
