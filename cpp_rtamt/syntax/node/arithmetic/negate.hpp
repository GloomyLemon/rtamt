#ifndef STL_NEG_NODE_H
#define STL_NEG_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class NegateNode : public UnaryNode {
    public:
        NegateNode(const PNode& child);

        NodeType getType() const override {
            return NodeType::Negate;
        }

    };
}

#endif