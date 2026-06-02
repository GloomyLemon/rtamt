#ifndef STL_ADD_NODE_H
#define STL_ADD_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {


    class AdditionNode : public BinaryNode {
    public:
        AdditionNode(const PNode& lchild, const PNode& rchild);

        NodeType getType() const override {
            return NodeType::Addition;
        }

    };
}

#endif