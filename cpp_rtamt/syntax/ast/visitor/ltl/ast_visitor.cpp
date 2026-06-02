#include <ast/visitor/ltl/ast_visitor.hpp>
#include <node/abstract_node.hpp>

#include <ast/visitor/abstract_ast_visitor.hpp>

using namespace stl_library;

LtlAstVisitor::LtlAstVisitor() : AbstractAstVisitor() {
}


double LtlAstVisitor::visit(const PNode& node) {
    switch (node->getType()) {

    case AbstractNode::NodeType::Variable:
        return visitVariable(node);

    case AbstractNode::NodeType::Constant:
        return visitConstant(node);

    case AbstractNode::NodeType::Addition:
        return visitAddition(node);

    case AbstractNode::NodeType::Subtraction:
        return visitSubtraction(node);

    case AbstractNode::NodeType::Multiplication:
        return visitMultiplication(node);

    case AbstractNode::NodeType::Division:
        return visitDivision(node);

    case AbstractNode::NodeType::Exp:
        return visitExp(node);

    case AbstractNode::NodeType::Pow:
        return visitPow(node);

    case AbstractNode::NodeType::Log:
        return visitLog(node);

    case AbstractNode::NodeType::Ln:
        return visitLn(node);

    case AbstractNode::NodeType::Sqrt:
        return visitSqrt(node);

    case AbstractNode::NodeType::Negate:
        return visitNegate(node);

    case AbstractNode::NodeType::Abs:
        return visitAbs(node);

    case AbstractNode::NodeType::Always:
        return visitAlways(node);

    case AbstractNode::NodeType::Eventually:
        return visitEventually(node);

    case AbstractNode::NodeType::Disjunction:
        return visitDisjunction(node);

    case AbstractNode::NodeType::Conjunction:
        return visitConjunction(node);

    case AbstractNode::NodeType::Until:
        return visitUntil(node);

    case AbstractNode::NodeType::Since:
        return visitSince(node);

    case AbstractNode::NodeType::Historically:
        return visitHistorically(node);

    case AbstractNode::NodeType::Once:
        return visitOnce(node);

    case AbstractNode::NodeType::Rise:
        return visitRise(node);

    case AbstractNode::NodeType::Fall:
        return visitFall(node);

    case AbstractNode::NodeType::Next:
        return visitNext(node);

    case AbstractNode::NodeType::StrongNext:
        return visitStrongNext(node);

    case AbstractNode::NodeType::Previous:
        return visitPrevious(node);

    case AbstractNode::NodeType::StrongPrevious:
        return visitStrongPrevious(node);

    case AbstractNode::NodeType::Implies:
        return visitImplies(node);

    case AbstractNode::NodeType::Iff:
        return visitIff(node);

    case AbstractNode::NodeType::Xor:
        return visitXor(node);

    case AbstractNode::NodeType::Not:
        return visitNot(node);

    case AbstractNode::NodeType::Predicate:
        return visitPredicate(node);

    default:
        // Optional: error handling
        return 0;
    }
}



double LtlAstVisitor::visitPredicate(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitVariable(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitConstant(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitNot(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitDisjunction(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitConjunction(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitImplies(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitIff(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitXor(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitEventually(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitAlways(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitUntil(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitOnce(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitHistorically(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitSince(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitAbs(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitSqrt(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitExp(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitPow(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitLog(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitLn(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitAddition(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitSubtraction(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitMultiplication(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitDivision(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitNegate(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitRise(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitFall(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitPrevious(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitStrongPrevious(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitNext(const PNode& node) { return this->visitChildren(node); }
double LtlAstVisitor::visitStrongNext(const PNode& node) { return this->visitChildren(node); }

/**
/from rtamt.syntax.ast.visitor.abstract_ast_visitor import AbstractAstVisitor

from rtamt.syntax.node.ltl.predicate import Predicate
from rtamt.syntax.node.ltl.strong_next import StrongNext
from rtamt.syntax.node.ltl.strong_previous import StrongPrevious
from rtamt.syntax.node.ltl.variable import Variable
from rtamt.syntax.node.ltl.neg import Neg
from rtamt.syntax.node.ltl.disjunction import Disjunction
from rtamt.syntax.node.ltl.conjunction import Conjunction
from rtamt.syntax.node.ltl.implies import Implies
from rtamt.syntax.node.ltl.iff import Iff
from rtamt.syntax.node.ltl.xor import Xor
from rtamt.syntax.node.ltl.eventually import Eventually
from rtamt.syntax.node.ltl.always import Always
from rtamt.syntax.node.ltl.until import Until
from rtamt.syntax.node.ltl.once import Once
from rtamt.syntax.node.ltl.historically import Historically
from rtamt.syntax.node.ltl.since import Since
from rtamt.syntax.node.arithmetic.abs import Abs
from rtamt.syntax.node.arithmetic.exp import Exp
from rtamt.syntax.node.arithmetic.pow import Pow
from rtamt.syntax.node.arithmetic.log import Log
from rtamt.syntax.node.arithmetic.ln import Ln
from rtamt.syntax.node.arithmetic.sqrt import Sqrt
from rtamt.syntax.node.arithmetic.addition import Addition
from rtamt.syntax.node.arithmetic.subtraction import Subtraction
from rtamt.syntax.node.arithmetic.negate import Negate
from rtamt.syntax.node.arithmetic.multiplication import Multiplication
from rtamt.syntax.node.arithmetic.division import Division
from rtamt.syntax.node.ltl.rise import Rise
from rtamt.syntax.node.ltl.fall import Fall
from rtamt.syntax.node.ltl.constant import Constant
from rtamt.syntax.node.ltl.next import Next
from rtamt.syntax.node.ltl.previous import Previous

from rtamt.exception.exception import RTAMTException


class LtlAstVisitor(AbstractAstVisitor):

    def visit(self, node, *args, **kwargs):
        if isinstance(node, Predicate):
            result = self.visitPredicate(node, *args, **kwargs)
        elif isinstance(node, Variable):
            result = self.visitVariable(node, *args, **kwargs)
        elif isinstance(node, Neg):
            result = self.visitNot(node, *args, **kwargs)
        elif isinstance(node, Disjunction):
            result = self.visitOr(node, *args, **kwargs)
        elif isinstance(node, Conjunction):
            result = self.visitAnd(node, *args, **kwargs)
        elif isinstance(node, Implies):
            result = self.visitImplies(node, *args, **kwargs)
        elif isinstance(node, Iff):
            result = self.visitIff(node, *args, **kwargs)
        elif isinstance(node, Xor):
            result = self.visitXor(node, *args, **kwargs)
        elif isinstance(node, Eventually):
            result = self.visitEventually(node, *args, **kwargs)
        elif isinstance(node, Always):
            result = self.visitAlways(node, *args, **kwargs)
        elif isinstance(node, Until):
            result = self.visitUntil(node, *args, **kwargs)
        elif isinstance(node, Once):
            result = self.visitOnce(node, *args, **kwargs)
        elif isinstance(node, Historically):
            result = self.visitHistorically(node, *args, **kwargs)
        elif isinstance(node, Since):
            result = self.visitSince(node, *args, **kwargs)
        elif isinstance(node, Abs):
            result = self.visitAbs(node, *args, **kwargs)
        elif isinstance(node, Sqrt):
            result = self.visitSqrt(node, *args, **kwargs)
        elif isinstance(node, Exp):
            result = self.visitExp(node, *args, **kwargs)
        elif isinstance(node, Pow):
            result = self.visitPow(node, *args, **kwargs)
        elif isinstance(node, Log):
            result = self.visitLog(node, *args, **kwargs)
        elif isinstance(node, Ln):
            result = self.visitLn(node, *args, **kwargs)
        elif isinstance(node, Addition):
            result = self.visitAddition(node, *args, **kwargs)
        elif isinstance(node, Subtraction):
            result = self.visitSubtraction(node, *args, **kwargs)
        elif isinstance(node, Negate):
            result = self.visitNegate(node, *args, **kwargs)
        elif isinstance(node, Multiplication):
            result = self.visitMultiplication(node, *args, **kwargs)
        elif isinstance(node, Division):
            result = self.visitDivision(node, *args, **kwargs)
        elif isinstance(node, Rise):
            result = self.visitRise(node, *args, **kwargs)
        elif isinstance(node, Fall):
            result = self.visitFall(node, *args, **kwargs)
        elif isinstance(node, Constant):
            result = self.visitConstant(node, *args, **kwargs)
        elif isinstance(node, Previous):
            result = self.visitPrevious(node, *args, **kwargs)
        elif isinstance(node, Next):
            result = self.visitNext(node, *args, **kwargs)
        elif isinstance(node, StrongPrevious):
            result = self.visitStrongPrevious(node, *args, **kwargs)
        elif isinstance(node, StrongNext):
            result = self.visitStrongNext(node, *args, **kwargs)
        else:
            self.raise_exception('{} is not a TL operator'.format(node.__class__.__name__))
        return result

    def raise_exception(self, text):
        raise RTAMTException(text)

    def visitPredicate(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitVariable(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitAbs(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitSqrt(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitPow(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitLog(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitLn(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitExp(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitAddition(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitSubtraction(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitNegate(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitMultiplication(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitDivision(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitNot(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitAnd(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitOr(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitImplies(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitIff(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitXor(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitEventually(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitAlways(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitUntil(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitOnce(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitHistorically(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitSince(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitRise(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitFall(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitConstant(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitPrevious(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitNext(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitStrongPrevious(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitStrongNext(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitDefault(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

*/