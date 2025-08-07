#include <stl/discrete_time/online/cpp/ast_visitor.hpp>

#include <abstract_online_operation.hpp>

#include <rtamt_stl_library/include/stl_predicate_node.h>
#include <node/ltl/predicate.hpp>
#include <node/ltl/constant.hpp>

#include <rtamt_stl_library/include/stl_var_node.h>
#include <rtamt_stl_library/include/stl_constant_node.h>
#include <rtamt_stl_library/include/stl_abs_node.h>
#include <rtamt_stl_library/include/stl_addition_node.h>
#include <rtamt_stl_library/include/stl_always_node.h>
#include <rtamt_stl_library/include/stl_division_node.h>
#include <rtamt_stl_library/include/stl_eventually_node.h>
#include <rtamt_stl_library/include/stl_exp_node.h>
#include <rtamt_stl_library/include/stl_fall_node.h>
#include <rtamt_stl_library/include/stl_historically_node.h>
#include <rtamt_stl_library/include/stl_historically_bounded_node.h>
#include <rtamt_stl_library/include/stl_ln_node.h>
#include <rtamt_stl_library/include/stl_log_node.h>
#include <rtamt_stl_library/include/stl_multiplication_node.h>
#include <rtamt_stl_library/include/stl_negate_node.h>
#include <rtamt_stl_library/include/stl_not_node.h>
#include <rtamt_stl_library/include/stl_once_node.h>
#include <rtamt_stl_library/include/stl_once_bounded_node.h>
#include <rtamt_stl_library/include/stl_pow_node.h>
#include <rtamt_stl_library/include/stl_precedes_bounded_node.h>
//#include <rtamt_stl_library/include/stl_precedes_node.h>
#include <rtamt_stl_library/include/stl_predicate_node.h>
#include <rtamt_stl_library/include/stl_previous_node.h>
#include <rtamt_stl_library/include/stl_rise_node.h>
#include <rtamt_stl_library/include/stl_since_bounded_node.h>
#include <rtamt_stl_library/include/stl_since_node.h>
#include <rtamt_stl_library/include/stl_sqrt_node.h>
#include <rtamt_stl_library/include/stl_subtraction_node.h>

#include <rtamt_stl_library/include/stl_combinatorial_binary_node.h>

#include<iostream>

using namespace stl_library;

#include <memory>
#include <rtamt_stl_library/include/stl_operator_type.h>

std::unordered_map<std::string, POperation> StlDiscreteTimeOnlineAstVisitor::getOnlineOperatorDict(const PNode& node) {
    visit(node);
    return online_operator_dict;
}

double StlDiscreteTimeOnlineAstVisitor::visitPredicate(const PNode& node) { 
    std::shared_ptr<PredicateNode> pred = std::static_pointer_cast<PredicateNode>(node);
    POperation pop = std::make_shared<StlPredicateNode>(pred->getOperator());
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node); 
}

double StlDiscreteTimeOnlineAstVisitor::visitVariable(const PNode& node) {
    POperation pop = std::make_shared<StlVarNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node); 
}

double StlDiscreteTimeOnlineAstVisitor::visitConstant(const PNode& node) {
    std::shared_ptr<ConstantNode> constant = std::static_pointer_cast<ConstantNode>(node);
    POperation pop = std::make_shared<StlConstantNode>(constant->getValue());
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitNot(const PNode& node) {
    POperation pop = std::make_shared<StlNotNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitDisjunction(const PNode& node) {
    POperation pop = std::make_shared<StlCombinatorialBinaryNode>(StlOperatorType::OR);
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitConjunction(const PNode& node) {
    POperation pop = std::make_shared<StlCombinatorialBinaryNode>(StlOperatorType::AND);
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitImplies(const PNode& node) {
    POperation pop = std::make_shared<StlCombinatorialBinaryNode>(StlOperatorType::IMPLIES);
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitIff(const PNode& node) {
    POperation pop = std::make_shared<StlCombinatorialBinaryNode>(StlOperatorType::IFF);
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitXor(const PNode& node) {
    POperation pop = std::make_shared<StlCombinatorialBinaryNode>(StlOperatorType::XOR);
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitEventually(const PNode& node) {
    POperation pop = std::make_shared<StlEventuallyNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitAlways(const PNode& node) {
    POperation pop = std::make_shared<StlAlwaysNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
//std::vector<double> StlDiscreteTimeOnlineAstVisitor::visitUntil(const PNode& node) {
//    POperation pop = std::make_shared<StlUntilNode>();
//    online_operator_dict[node->getName()] = pop;
//    return this->visitChildren(node);
//}
double StlDiscreteTimeOnlineAstVisitor::visitOnce(const PNode& node) {
    POperation pop = std::make_shared<StlOnceNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitHistorically(const PNode& node) {
    POperation pop = std::make_shared<StlHistoricallyNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitSince(const PNode& node) {
    POperation pop = std::make_shared<StlSinceNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitAbs(const PNode& node) {
    POperation pop = std::make_shared<StlAbsNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitSqrt(const PNode& node) {
    POperation pop = std::make_shared<StlSqrtNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitExp(const PNode& node) {
    POperation pop = std::make_shared<StlExpNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitPow(const PNode& node) {
    POperation pop = std::make_shared<StlPowNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitLog(const PNode& node) {
    POperation pop = std::make_shared<StlLogNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitLn(const PNode& node) {
    POperation pop = std::make_shared<StlLnNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitAddition(const PNode& node) {
    POperation pop = std::make_shared<StlAdditionNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitSubtraction(const PNode& node) {
    POperation pop = std::make_shared<StlSubtractionNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitMultiplication(const PNode& node) {
    POperation pop = std::make_shared<StlMultiplicationNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitDivision(const PNode& node) {
    POperation pop = std::make_shared<StlDivisionNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitNegate(const PNode& node) {
    POperation pop = std::make_shared<StlNegateNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitRise(const PNode& node) {
    POperation pop = std::make_shared<StlRiseNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitFall(const PNode& node) {
    POperation pop = std::make_shared<StlFallNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitPrevious(const PNode& node) {
    POperation pop = std::make_shared<StlPreviousNode>();
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
//double StlDiscreteTimeOnlineAstVisitor::visitStrongPrevious(const PNode& node) {
//    POperation pop = std::make_shared<StlPreviousNode>();
//    online_operator_dict[node->getName()] = pop;
//    return this->visitChildren(node);
//}
//double StlDiscreteTimeOnlineAstVisitor::visitNext(const PNode& node) {
//    POperation pop = std::make_shared<StlNextNode>();
//    online_operator_dict[node->getName()] = pop;
//    return this->visitChildren(node);
//}
//double StlDiscreteTimeOnlineAstVisitor::visitStrongNext(const PNode& node) {
//    POperation pop = std::make_shared<StlNextNode>();
//    online_operator_dict[node->getName()] = pop;
//    return this->visitChildren(node);
//}
//double StlDiscreteTimeOnlineAstVisitor::visitTimedAlways(const PNode& node) {
//    POperation pop = std::make_shared<StlAlwaysNode>();
//    online_operator_dict[node->getName()] = pop;
//    return this->visitChildren(node);
//}
//double StlDiscreteTimeOnlineAstVisitor::visitTimedEventually(const PNode& node) {
//    POperation pop = std::make_shared<StlAdditionNode>();
//    online_operator_dict[node->getName()] = pop;
//    return this->visitChildren(node);
//    }
double StlDiscreteTimeOnlineAstVisitor::visitTimedHistorically(const PNode& node) {
    POperation pop = std::make_shared<StlHistoricallyBoundedNode>(0, 1);
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitTimedOnce(const PNode& node) {
    POperation pop = std::make_shared<StlOnceBoundedNode>(0, 1);
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitTimedPrecedes(const PNode& node) {
    POperation pop = std::make_shared<StlPrecedesBoundedNode>(0, 1);
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
double StlDiscreteTimeOnlineAstVisitor::visitTimedSince(const PNode& node) {
    POperation pop = std::make_shared<StlSinceBoundedNode>(0, 1);
    online_operator_dict[node->getName()] = pop;
    return this->visitChildren(node);
}
//double StlDiscreteTimeOnlineAstVisitor::visitTimedUntil(const PNode& node) {
//    POperation pop = std::make_shared<StlAdditionNode>();
//    online_operator_dict[node->getName()] = pop;
//    return this->visitChildren(node);
//}

/*
* from rtamt.syntax.ast.visitor.stl.ast_visitor import StlAstVisitor

import rtamt.lib.rtamt_stl_library_wrapper.load_dlls as loader
loader.init_dlls()

from rtamt.semantics.enumerations.comp_op import StlComparisonOperator as CompOp
from rtamt.lib.rtamt_stl_library_wrapper.stl_combinatorial_binary_node import CombinatorialBinaryOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_comp_op import StlComparisonOperator
from rtamt.lib.rtamt_stl_library_wrapper.stl_not_node import NotOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_addition_node import AdditionOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_predicate_node import PredicateOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_multiplication_node import MultiplicationOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_subtraction_node import SubtractionOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_division_node import DivisionOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_and_node import AndOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_or_node import OrOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_implies_node import ImpliesOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_iff_node import IffOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_xor_node import XorOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_since_node import SinceOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_abs_node import AbsOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_exp_node import ExpOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_pow_node import PowOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_log_node import LogOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_ln_node import LnOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_negate_node import NegateOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_sqrt_node import SqrtOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_rise_node import RiseOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_fall_node import FallOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_once_node import OnceOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_historically_node import HistoricallyOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_always_node import AlwaysOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_eventually_node import EventuallyOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_previous_node import PreviousOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_constant_node import ConstantOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_var_node import VariableOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_once_bounded_node import OnceBoundedOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_historically_bounded_node import HistoricallyBoundedOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_since_bounded_node import SinceBoundedOperation
from rtamt.lib.rtamt_stl_library_wrapper.stl_precedes_bounded_node import PrecedesBoundedOperation

from rtamt.exception.exception import RTAMTException


class StlDiscreteTimeOnlineAstVisitorCpp(StlAstVisitor):

    def visitConstant(self, node, *args, **kwargs):
        self.online_operator_dict[node.name] = ConstantOperation(node.val)

    def visitVariable(self, node, *args, **kwargs):
        self.online_operator_dict[node.name] = VariableOperation()

    def visitPredicate(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = PredicateOperation(self.op_cpp(node.operator))

    def visitAbs(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = AbsOperation()

    def visitPow(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = PowOperation()

    def visitLog(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = LogOperation()

    def visitLn(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = LnOperation()

    def visitExp(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = ExpOperation()


    def visitNegate(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = NegateOperation()

    def visitSqrt(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = SqrtOperation()

    def visitAddition(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = AdditionOperation()

    def visitSubtraction(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = SubtractionOperation()

    def visitMultiplication(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = MultiplicationOperation()

    def visitDivision(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = DivisionOperation()

    def visitNot(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = NotOperation()

    def visitAnd(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = AndOperation()

    def visitOr(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = OrOperation()

    def visitImplies(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = ImpliesOperation()

    def visitIff(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = IffOperation()

    def visitXor(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = XorOperation()

    def visitEventually(self, node, *args, **kwargs):
        #self.visitChildren(node, *args, **kwargs)
        #self.online_operator_dict[node.name] = EventuallyOperation()
        raise RTAMTException('Eventually operator is not implemented in the STL online monitor.')

    def visitAlways(self, node, *args, **kwargs):
        #self.visitChildren(node, *args, **kwargs)
        #self.online_operator_dict[node.name] = AlwaysOperation()
        raise RTAMTException('Always operator is not implemented in the STL online monitor.')

    def visitUntil(self, node, *args, **kwargs):
        raise RTAMTException('Until operator is not implemented in the STL online monitor.')

    def visitOnce(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = OnceOperation()

    def visitHistorically(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = HistoricallyOperation()

    def visitSince(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = SinceOperation()

    def visitRise(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = RiseOperation()

    def visitFall(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = FallOperation()

    def visitPrevious(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        self.online_operator_dict[node.name] = PreviousOperation()

    def visitNext(self, node, *args, **kwargs):
        raise RTAMTException('Next operator not implemented in STL online monitor.')

    def visitTimedPrecedes(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        begin, end = self.time_unit_transformer(node)
        self.online_operator_dict[node.name] = PrecedesBoundedOperation(begin, end)

    def visitTimedOnce(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        begin, end = self.time_unit_transformer(node)
        self.online_operator_dict[node.name] = OnceBoundedOperation(begin, end)

    def visitTimedHistorically(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        begin, end = self.time_unit_transformer(node)
        self.online_operator_dict[node.name] = HistoricallyBoundedOperation(begin, end)

    def visitTimedSince(self, node, *args, **kwargs):
        self.visitChildren(node, *args, **kwargs)
        begin, end = self.time_unit_transformer(node)
        self.online_operator_dict[node.name] = SinceBoundedOperation(begin, end)

    def visitTimedAlways(self, node, *args, **kwargs):
        raise RTAMTException('Bounded always operator not implemented in STL online monitor.')

    def visitTimedEventually(self, node, *args, **kwargs):
        raise RTAMTException('Bounded eventually operator not implemented in STL online monitor.')

    def visitTimedUntil(self, node, *args, **kwargs):
        raise RTAMTException('Bounded until operator not implemented in STL online monitor.')

    def op_cpp(self, op):
        if op == CompOp.GEQ:
            return StlComparisonOperator.GEQ
        elif op == CompOp.GREATER:
            return StlComparisonOperator.GREATER
        elif op == CompOp.LEQ:
            return StlComparisonOperator.LEQ
        elif op == CompOp.LESS:
            return StlComparisonOperator.LESS
        elif op == CompOp.NEQ:
            return StlComparisonOperator.NEQ
        elif op == CompOp.EQUAL:
            return StlComparisonOperator.EQUAL
        else:
            raise RTAMTException('Could not find operator {}!'.format(op))

*/