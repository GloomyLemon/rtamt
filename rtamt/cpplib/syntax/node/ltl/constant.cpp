#include <node/ltl/constant.hpp>

#include <string>

using namespace stl_library;

ConstantNode::ConstantNode(const double val) {
    value = val;
    name = std::to_string(val);
}


/*
* -*- coding: utf-8 -*-
"""
Created on Sun Jul 21 22:30:09 2019

@author: NickovicD
"""

from rtamt.syntax.node.leaf_node import LeafNode

class Constant(LeafNode):
    """A class for storing STL real-valued Constant nodes
                Inherits Node

    Attributes:
        val : double
    """
    def __init__(self, val):
        """Constructor for Const node

        Parameters:
            val : double
        """

        super(Constant, self).__init__()
        self.val = val

        self.name = str(val)


    @property
    def val(self):
        """Getter for val"""
        return self.__val
    
    @val.setter
    def val(self, val):
        """Setter for child"""
        self.__val = val
        

*/