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

/*
* from rtamt.semantics.interval.interval import Interval
from rtamt.syntax.node.binary_node import BinaryNode

class TimedSince(BinaryNode, Interval):
    """A class for storing STL Since nodes
                Inherits TemporalNode
    """
    def __init__(self, child1, child2, interval, is_pure_python=True):
        """Constructor for Since node

            Parameters:
                child1 : stl.Node
                child2 : stl.Node
                bound : Interval
        """

        BinaryNode.__init__(self, child1, child2)
        Interval.__init__(self, interval.begin, interval.end, interval.begin_unit, interval.end_unit)

        self.in_vars = child1.in_vars + child2.in_vars
        self.out_vars = child1.out_vars + child2.out_vars

        self.name = '(' + child1.name + ')since[' + str(self.begin) + str(self.begin_unit) + ',' + str(
                self.end) + str(self.end_unit) + '](' + child2.name + ')'
*/
