#include <node/unary_node.hpp>

using namespace stl_library;

UnaryNode::UnaryNode(const PNode& c) {
    add_child(c);
}


/**
from rtamt.syntax.node.abstract_node import AbstractNode


class UnaryNode(AbstractNode):

    def __init__(self, child):
        """Constructor for Node"""
        super(UnaryNode, self).__init__()
        self.add_child(child)
*/


