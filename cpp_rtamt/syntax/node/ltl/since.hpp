#ifndef STL_SINCE_NODE_H
#define STL_SINCE_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {


    class SinceNode : public BinaryNode {
    public:
        SinceNode(const PNode& lchild, const PNode& rchild);

        NodeType getType() const override {
            return NodeType::Since;
        }

    };
}

#endif
