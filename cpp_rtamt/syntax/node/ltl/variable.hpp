#ifndef STL_VAR_NODE_H
#define STL_VAR_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/leaf_node.hpp>

namespace stl_library {


    class VariableNode : public LeafNode {
    public:
        VariableNode(std::string var);

        NodeType getType() const override {
            return NodeType::Variable;
        }

        };
}

#endif
