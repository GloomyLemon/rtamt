#ifndef STL_SPREV_NODE_H
#define STL_SPREV_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class StrongPreviousNode : public UnaryNode {
    public:
        StrongPreviousNode(const PNode& child);

        NodeType getType() const override {
            return NodeType::StrongPrevious;
        }

    };
}

#endif
