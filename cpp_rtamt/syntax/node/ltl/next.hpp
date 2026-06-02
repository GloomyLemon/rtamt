#ifndef STL_NEXT_NODE_H
#define STL_NEXT_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class NextNode : public UnaryNode {
    public:
        NextNode(const PNode& child);

        NodeType getType() const override {
            return NodeType::Next;
        }

    };
}

#endif
