#ifndef STL_CONST_NODE_H
#define STL_CONST_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/leaf_node.hpp>

namespace stl_library {


    class ConstantNode : public LeafNode {
    private:
        double value;
    public:
        ConstantNode() = delete;
        ConstantNode(double val);

        NodeType getType() const override {
            return NodeType::Constant;
        }


        double getValue() const { return value; }
    };
}

#endif
