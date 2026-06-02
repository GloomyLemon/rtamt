#ifndef STL_SNEXT_NODE_H
#define STL_SNEXT_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class StrongNextNode : public UnaryNode {
    public:
        StrongNextNode(const PNode& child);

        NodeType getType() const override {
            return NodeType::StrongNext;
        }

    };
}

#endif
