#ifndef STL_BINARY_NODE_H
#define STL_BINARY_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/abstract_node.hpp>

namespace stl_library {

    class BinaryNode : public AbstractNode {
    public:
        BinaryNode();
        BinaryNode(const PNode& l, const PNode& r);

    };
}

#endif

/**
/from rtamt.syntax.node.abstract_node import AbstractNode


class BinaryNode(AbstractNode):

    def __init__(self, left_child, right_child):
        """Constructor for Node"""
        super(BinaryNode, self).__init__()
        self.add_child(left_child)
        self.add_child(right_child)
*/