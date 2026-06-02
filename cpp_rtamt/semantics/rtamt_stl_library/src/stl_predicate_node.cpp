#include <rtamt_stl_library/include/stl_predicate_node.h>
#include <cmath>
#include <rtamt_stl_library/include/stl_comp_op.h>

using namespace stl_library;

StlPredicateNode::StlPredicateNode(OperatorType op) {
    this->op = op;
}

void StlPredicateNode::reset() {
}

double StlPredicateNode::update(double left, double right) {
    double out = 0;
    
    switch(op) {
        case OperatorType::EQ:
            out = -std::abs(left - right);
            break;
            case OperatorType::NEQ:
            out = std::abs(left - right);
            break;
        case OperatorType::LEQ:
        case OperatorType::LESS:
            out = right - left;
            break;
        case OperatorType::GEQ:
        case OperatorType::GREATER:
            out = left - right;
            break;
    }
    
    return out;
}
