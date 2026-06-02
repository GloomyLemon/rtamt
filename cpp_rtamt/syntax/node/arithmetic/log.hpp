#ifndef STL_LOG_NODE_H
#define STL_LOG_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {


    class LogNode : public BinaryNode {
    public:
        LogNode(const PNode& lchild, const PNode& rchild);

        NodeType getType() const override {
            return NodeType::Log;
        }

    };
}

#endif