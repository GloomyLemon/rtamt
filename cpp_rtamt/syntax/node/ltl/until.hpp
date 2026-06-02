#ifndef STL_UNTIL_NODE_H
#define STL_UNTIL_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {


    class UntilNode : public BinaryNode {
    public:
        UntilNode(const PNode& lchild, const PNode& rchild);

        NodeType getType() const override {
            return NodeType::Until;
        }

    };
}

#endif