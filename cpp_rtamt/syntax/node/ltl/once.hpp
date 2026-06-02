#ifndef STL_ONCE_NODE_H
#define STL_ONCE_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class OnceNode : public UnaryNode {
    public:
        OnceNode(const PNode& child);

        NodeType getType() const override {
            return NodeType::Once;
        }

    };
}

#endif