#ifndef STL_TALW_NODE_H
#define STL_TALW_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>
#include <interval/interval.hpp>

namespace stl_library {


    class TimedAlwaysNode : public UnaryNode {
    private:
        Interval interval;
    public:
        TimedAlwaysNode(const PNode& child, const Interval itv);
        Interval getInterval() { return interval; }
    };
}

#endif

/*
* # -*- coding: utf-8 -*-
"""
Created on Sun Jul 21 22:24:09 2019

@author: NickovicD
"""
from rtamt.semantics.interval.interval import Interval
from rtamt.syntax.node.unary_node import UnaryNode


class TimedAlways(UnaryNode, Interval):
    """A class for storing STL Always nodes
        Inherits TemporalNode
    """

    def __init__(self, child, interval, is_pure_python=True):
        """Constructor for Always

        Parameters:
            child : stl.Node
            bound : Interval
        """
        UnaryNode.__init__(self, child)
        Interval.__init__(self, interval.begin, interval.end, interval.begin_unit, interval.end_unit)

        self.in_vars = child.in_vars
        self.out_vars = child.out_vars

        self.name = 'always[' + str(self.begin) + str(self.begin_unit) + ',' + str(self.end) + str(self.end_unit) + '](' + child.name + ')'





*/