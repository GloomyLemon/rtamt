#ifndef STL_TSIN_NODE_H
#define STL_TSIN_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>
#include <interval/interval.hpp>

namespace stl_library {


    class TimedSinceNode : public BinaryNode {
    private:
        Interval interval;
    public:
        TimedSinceNode(const PNode& lchild, const PNode& rchild, const Interval itv);
        Interval getInterval() { return interval; }
    };
}

#endif

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
