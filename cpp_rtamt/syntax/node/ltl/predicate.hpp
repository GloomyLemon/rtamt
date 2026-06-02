#ifndef STL_PRED_NODE_H
#define STL_PRED_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {

    enum class OperatorType { EQ, NEQ, LEQ, LESS, GEQ, GREATER};


    class PredicateNode : public BinaryNode {
    private:
        OperatorType op;

    public:
        PredicateNode(const PNode& lchild, const PNode& rchild, OperatorType oper);

        NodeType getType() const override {
            return NodeType::Predicate;
        }


        OperatorType getOperator() { return op; }
        std::string getOperatorString() {
            switch (op) {
            case OperatorType::EQ:
                return "=";
            case OperatorType::NEQ:
                return "!=";
            case OperatorType::LESS:
                return "<";
            case OperatorType::LEQ:
                return "<=";
            case OperatorType::GREATER:
                return ">";
            case OperatorType::GEQ:
                return ">=";
            default:
                return "ERROR";
            }

        }
    };
}

#endif
