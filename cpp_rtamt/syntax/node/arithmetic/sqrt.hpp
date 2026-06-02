#ifndef STL_SQRT_NODE_H
#define STL_SQRT_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class SqrtNode : public UnaryNode {
    public:
        SqrtNode(const PNode& child);

        NodeType getType() const override {
            return NodeType::Sqrt;
        }

    };
}

#endif
