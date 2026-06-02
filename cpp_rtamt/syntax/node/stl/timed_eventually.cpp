#include <node/stl/timed_eventually.hpp>

using namespace stl_library;

TimedEventuallyNode::TimedEventuallyNode(const PNode& child, const Interval itv) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    interval = itv;
    name = "F[" + std::to_string(interval.getBegin()) + "," + std::to_string(interval.getEnd()) + "](" + child->getName() + ")";

}

