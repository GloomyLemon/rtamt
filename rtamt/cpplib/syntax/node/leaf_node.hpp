#ifndef STL_LEAF_NODE_H
#define STL_LEAF_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/abstract_node.hpp>

namespace stl_library {


    class LeafNode : public AbstractNode {
    public:
        LeafNode();
    };
}

#endif

/**
from rtamt.syntax.node.abstract_node import AbstractNode


class LeafNode(AbstractNode):

    def __init__(self):
        super(LeafNode, self).__init__()
*/

