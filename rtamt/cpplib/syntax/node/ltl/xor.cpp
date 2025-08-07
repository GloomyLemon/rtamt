#include <node/ltl/xor.hpp>

using namespace stl_library;

XorNode::XorNode(const PNode& lchild, const PNode& rchild) : BinaryNode(lchild, rchild) {
    inVars = lchild->getInVars();
    inVars.insert(inVars.end(), rchild->getInVars().begin(), rchild->getInVars().end());
    outVars = rchild->getOutVars();
    outVars.insert(outVars.end(), rchild->getOutVars().begin(), rchild->getOutVars().end());
    name = "( " + lchild->getName() + ")xor(" + rchild->getName() + " )";
}

/*
* # -*- coding: utf-8 -*-
"""
Created on Sun Jul 21 22:24:09 2019

@author: NickovicD
"""
from rtamt.syntax.node.binary_node import BinaryNode


class Xor(BinaryNode):
    """A class for storing STL Xor nodes
        Inherits TemporalNode
    """
    def __init__(self, child1, child2):
        """Constructor for Xor node

        Parameters:
            child1 : stl.Node
            child2 : stl.Node
        """
        super(BinaryNode, self).__init__()
        self.add_child(child1)
        self.add_child(child2)

        self.name = '(' + child1.name + ')xor(' + child2.name + ')'
*/