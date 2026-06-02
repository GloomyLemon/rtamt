#ifndef STL_MUL_NODE_H
#define STL_MUL_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {


    class MultiplicationNode : public BinaryNode {
    public:
        MultiplicationNode(const PNode& lchild, const PNode& rchild);

        NodeType getType() const override {
            return NodeType::Multiplication;
        }

    };
}

#endif
