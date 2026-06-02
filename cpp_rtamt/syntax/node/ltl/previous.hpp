#ifndef STL_PREV_NODE_H
#define STL_PREV_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class PreviousNode : public UnaryNode {
    public:
        PreviousNode(const PNode& child);

        NodeType getType() const override {
            return NodeType::Previous;
        }

    };
}

#endif




