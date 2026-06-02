#ifndef STL_IFF_NODE_H
#define STL_IFF_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {


    class IffNode : public BinaryNode {
    public:
        IffNode(const PNode& lchild, const PNode& rchild);

        NodeType getType() const override {
            return NodeType::Iff;
        }

    };
}

#endif
