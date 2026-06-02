#ifndef STL_NOT_NODE_H
#define STL_NOT_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class NotNode : public UnaryNode {
    public:
        NotNode(const PNode& child);

        NodeType getType() const override {
            return NodeType::Not;
        }

    };
}

#endif
