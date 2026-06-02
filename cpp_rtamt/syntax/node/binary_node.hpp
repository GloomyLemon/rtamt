#ifndef STL_BINARY_NODE_H
#define STL_BINARY_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/abstract_node.hpp>

namespace stl_library {

    class BinaryNode : public AbstractNode {
    public:
        BinaryNode();
        BinaryNode(const PNode& l, const PNode& r);

    };
}

#endif
