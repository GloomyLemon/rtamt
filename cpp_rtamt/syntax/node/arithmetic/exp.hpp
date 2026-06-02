#pragma once

#pragma message("Including exp.hpp from: " __FILE__)

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class ExpNode : public UnaryNode {
    public:
        ExpNode(const PNode& child);

        NodeType getType() const override {
            return NodeType::Exp;
        }

    };
}