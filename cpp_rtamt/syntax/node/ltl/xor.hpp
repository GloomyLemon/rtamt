#ifndef STL_XOR_NODE_H
#define STL_XOR_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {


    class XorNode : public BinaryNode {
    public:
        XorNode(const PNode& lchild, const PNode& rchild);

        NodeType getType() const override {
            return NodeType::Xor;
        }

    };
}

#endif