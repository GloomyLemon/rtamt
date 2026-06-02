#ifndef STL_HIS_NODE_H
#define STL_HIS_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class HistoricallyNode : public UnaryNode {
    public:
        HistoricallyNode(const PNode& child);

        NodeType getType() const override {
            return NodeType::Historically;
        }

    };
}

#endif

