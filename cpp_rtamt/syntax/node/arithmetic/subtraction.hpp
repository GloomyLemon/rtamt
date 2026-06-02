#ifndef STL_SUB_NODE_H
#define STL_SUB_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {


    class SubtractionNode : public BinaryNode {
    public:
        SubtractionNode(const PNode& lchild, const PNode& rchild);

        NodeType getType() const override {
            return NodeType::Subtraction;
        }

    };
}

#endif
