#ifndef STL_RISE_NODE_H
#define STL_RISE_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class RiseNode : public UnaryNode {
    public:
        RiseNode(const PNode& child);

        NodeType getType() const override {
            return NodeType::Rise;
        }

    };
}

#endif




