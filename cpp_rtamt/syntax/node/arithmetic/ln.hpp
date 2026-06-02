#ifndef STL_LN_NODE_H
#define STL_LN_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class LnNode : public UnaryNode {
    public:
        LnNode(const PNode& child);

        NodeType getType() const override {
            return NodeType::Ln;
        }

    };
}

#endif

