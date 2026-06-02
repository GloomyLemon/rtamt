#ifndef STL_POW_NODE_H
#define STL_POW_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {


    class PowNode : public BinaryNode {
    public:
        PowNode(const PNode& lchild, const PNode& rchild);

        NodeType getType() const override {
            return NodeType::Pow;
        }

    };
}

#endif
