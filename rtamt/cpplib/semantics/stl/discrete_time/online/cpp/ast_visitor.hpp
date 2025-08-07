#pragma once

#include <node/abstract_node.hpp>
#include <ast/visitor/stl/ast_visitor.hpp>
#include <abstract_online_operation.hpp>

#include <unordered_map>

namespace stl_library {

    class StlDiscreteTimeOnlineAstVisitor : public StlAstVisitor {
    private:
        std::unordered_map<std::string, POperation> online_operator_dict;

    public:
        //StlDiscreteTimeOnlineAstVisitor();
        std::unordered_map<std::string, POperation> getOnlineOperatorDict(const PNode& node);
        //double visit(const PNode& node) override;
        double visitPredicate(const PNode& node);
        double visitVariable(const PNode& node);
        double visitConstant(const PNode& node);
        double visitNot(const PNode& node);
        double visitDisjunction(const PNode& node);
        double visitConjunction(const PNode& node);
        double visitImplies(const PNode& node);
        double visitIff(const PNode& node);
        double visitXor(const PNode& node);
        double visitEventually(const PNode& node);
        double visitAlways(const PNode& node);
        //double visitUntil(const PNode& node);
        double visitOnce(const PNode& node);
        double visitHistorically(const PNode& node);
        double visitSince(const PNode& node);
        double visitAbs(const PNode& node);
        double visitSqrt(const PNode& node);
        double visitExp(const PNode& node);
        double visitPow(const PNode& node);
        double visitLog(const PNode& node);
        double visitLn(const PNode& node);
        double visitAddition(const PNode& node);
        double visitSubtraction(const PNode& node);
        double visitMultiplication(const PNode& node);
        double visitDivision(const PNode& node);
        double visitNegate(const PNode& node);
        double visitRise(const PNode& node);
        double visitFall(const PNode& node);
        double visitPrevious(const PNode& node);
        //double visitStrongPrevious(const PNode& node);
        //double visitNext(const PNode& node);
        //double visitStrongNext(const PNode& node);
        //double visitTimedAlways(const PNode& node);
        //double visitTimedEventually(const PNode& node);
        double visitTimedHistorically(const PNode& node);
        double visitTimedOnce(const PNode& node);
        double visitTimedPrecedes(const PNode& node);
        double visitTimedSince(const PNode& node);
        //double visitTimedUntil(const PNode& node);
    };
}

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
