#ifndef STL_CONJ_NODE_H
#define STL_CONJ_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {


    class ConjunctionNode : public BinaryNode {
    public:
        ConjunctionNode(const PNode& lchild, const PNode& rchild);

        NodeType getType() const override {
            return NodeType::Conjunction;
        }

    };
}

#endif