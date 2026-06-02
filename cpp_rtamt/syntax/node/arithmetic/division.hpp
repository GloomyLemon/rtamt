#ifndef STL_DIV_NODE_H
#define STL_DIV_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {


    class DivisionNode : public BinaryNode {
    public:
        DivisionNode(const PNode& lchild, const PNode& rchild);

        NodeType getType() const override {
            return NodeType::Division;
        }

    };
}

#endif
