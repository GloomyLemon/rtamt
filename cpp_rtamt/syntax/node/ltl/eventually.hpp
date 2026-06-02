#ifndef STL_EVT_NODE_H
#define STL_EVT_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class EventuallyNode : public UnaryNode {
    public:
        EventuallyNode(const PNode& child);

        NodeType getType() const override {
            return NodeType::Eventually;
        }

    };
}

#endif
