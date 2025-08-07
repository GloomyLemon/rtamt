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

/*
* from rtamt.syntax.node.binary_node import BinaryNode

class Predicate(BinaryNode):
    """A class for storing STL real-valued Variable nodes
                Inherits Node

    Attributes:
        child1 : Node
        child2 : Node
        operator : OperatorType (LEQ, GEQ, LESS, GREATER, EQ or NEQ)
    """
    def __init__(self, child1, child2, operator):
        """Constructor for Predicate node

        Parameters:
            var : String
            field : String
            io_type : IOType enumeration (INPUT, OUTPUT or UNKNOWN)
            operator : OperatorType (LEQ, GEQ, LESS, GREATER, EQ or NEQ)
        """

        super(Predicate, self).__init__(child1, child2)
        self.operator = operator
        self.in_vars = child1.in_vars + child2.in_vars
        self.out_vars = child1.out_vars + child2.out_vars

        self.name = '(' + child1.name + ')' + str(self.operator) + '(' + child2.name + ')'


        
    @property
    def operator(self):
        """Getter for operator"""
        return self.__operator
    
    @operator.setter
    def operator(self, operator):
        """Setter for operator"""
        self.__operator = operator

*/