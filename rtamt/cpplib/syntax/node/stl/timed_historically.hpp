#ifndef STL_THIS_NODE_H
#define STL_THIS_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>
#include <interval/interval.hpp>

namespace stl_library {


    class TimedHistoricallyNode : public UnaryNode {
    private:
        Interval interval;
    public:
        TimedHistoricallyNode(const PNode& child, const Interval itv);
        Interval getInterval() { return interval; }
    };
}

#endif

/*
* from rtamt.semantics.interval.interval import Interval
from rtamt.syntax.node.unary_node import UnaryNode


class TimedHistorically(UnaryNode, Interval):

    def __init__(self, child, interval, is_pure_python=True):
        UnaryNode.__init__(self, child)
        Interval.__init__(self, interval.begin, interval.end, interval.begin_unit, interval.end_unit)
        self.in_vars = child.in_vars
        self.out_vars = child.out_vars

        self.name = 'historically[' + str(self.begin) + str(self.begin_unit) + ',' + str(self.end) + str(self.end_unit) + '](' + child.name + ')'
*/
