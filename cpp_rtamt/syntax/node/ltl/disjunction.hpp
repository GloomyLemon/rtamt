#ifndef STL_DISJ_NODE_H
#define STL_DISJ_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {


    class DisjunctionNode : public BinaryNode {
    public:
        DisjunctionNode(const PNode& lchild, const PNode& rchild);

        NodeType getType() const override {
            return NodeType::Disjunction;
        }

    };
}

#endif
