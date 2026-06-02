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