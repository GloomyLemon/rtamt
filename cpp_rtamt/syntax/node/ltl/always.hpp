#ifndef STL_ALW_NODE_H
#define STL_ALW_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class AlwaysNode : public UnaryNode {
    public:
        AlwaysNode(const PNode& child);

        NodeType getType() const override {
            return NodeType::Always;
        }

    };
}

#endif
