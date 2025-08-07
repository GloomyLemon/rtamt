#ifndef STL_UNARY_NODE_H
#define STL_UNARY_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/abstract_node.hpp>

namespace stl_library {


    class UnaryNode: public AbstractNode {

    public:
        UnaryNode() {};

        UnaryNode(const PNode& c);
    };
}

#endif

/**
from rtamt.syntax.node.abstract_node import AbstractNode


class UnaryNode(AbstractNode):

    def __init__(self, child):
        """Constructor for Node"""
        super(UnaryNode, self).__init__()
        self.add_child(child)

*/