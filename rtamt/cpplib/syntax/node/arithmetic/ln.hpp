#ifndef STL_LN_NODE_H
#define STL_LN_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class LnNode : public UnaryNode {
    public:
        LnNode(const PNode& child);
    };
}

#endif

/*
* # -*- coding: utf-8 -*-
"""
Created on Sun Jul 21 22:24:09 2019

@author: NickovicD
"""

from rtamt.syntax.node.unary_node import UnaryNode

class Ln(UnaryNode):
    """A class for storing STL Ln nodes
        Inherits Node
    """
    def __init__(self, child):
        """Constructor for Ln node

            Parameters:
                child : stl.Node
        """
        super(Ln, self).__init__(child)

        self.in_vars = child.in_vars
        self.out_vars = child.out_vars

        self.name = 'ln(' + child.name + ')'


*/
