#include <node/stl/timed_since.hpp>

using namespace stl_library;

TimedSinceNode::TimedSinceNode(const PNode& lchild, const PNode& rchild, const Interval itv) : BinaryNode(lchild, rchild) {
    inVars = lchild->getInVars();
    inVars.insert(inVars.end(), rchild->getInVars().begin(), rchild->getInVars().end());
    outVars = rchild->getOutVars();
    outVars.insert(outVars.end(), rchild->getOutVars().begin(), rchild->getOutVars().end());
    interval = itv;
    name = "( " + lchild->getName() + ")S[" + std::to_string(interval.getBegin()) + "," + std::to_string(interval.getEnd()) + "](" + rchild->getName() + ")";

}
