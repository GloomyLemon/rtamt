#ifndef STL_CONJ_NODE_H
#define STL_CONJ_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {


    class ConjunctionNode : public BinaryNode {
    public:
        ConjunctionNode(const PNode& lchild, const PNode& rchild);
    };
}

#endif

/*
* # -*- coding: utf-8 -*-
"""
Created on Sun Jul 21 22:24:09 2019

@author: NickovicD
"""

from rtamt.syntax.node.binary_node import BinaryNode


class Conjunction(BinaryNode):
    """A class for storing STL Conjunction nodes
        Inherits TemporalNode
    """
    def __init__(self, child1, child2):
        """Constructor for Conjunction node

            Parameters:
                child1 : stl.Node
                child2 : stl.Node
        """
        super(Conjunction, self).__init__(child1, child2)

        self.in_vars = child1.in_vars + child2.in_vars
        self.out_vars = child1.out_vars + child2.out_vars

        self.name = '(' + child1.name + ')and(' + child2.name + ')'


*/