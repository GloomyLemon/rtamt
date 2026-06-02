#ifndef STL_FALL_NODE_H
#define STL_FALL_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class FallNode : public UnaryNode {
    public:
        FallNode(const PNode& child);

        NodeType getType() const override {
            return NodeType::Fall;
        }

    };
}

#endif
