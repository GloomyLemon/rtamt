#pragma once

#include <node/abstract_node.hpp>
#include <ast/visitor/abstract_ast_visitor.hpp>

namespace stl_library {

    class LtlAstVisitor : public AbstractAstVisitor {
    private:

    public:
        LtlAstVisitor();
        double visit(const PNode& node) override;
        virtual double visitPredicate(const PNode& node);
        virtual double visitVariable(const PNode& node);
        virtual double visitConstant(const PNode& node);
        virtual double visitNot(const PNode& node);
        virtual double visitDisjunction(const PNode& node);
        virtual double visitConjunction(const PNode& node);
        virtual double visitImplies(const PNode& node);
        virtual double visitIff(const PNode& node);
        virtual double visitXor(const PNode& node);
        virtual double visitEventually(const PNode& node);
        virtual double visitAlways(const PNode& node);
        virtual double visitUntil(const PNode& node);
        virtual double visitOnce(const PNode& node);
        virtual double visitHistorically(const PNode& node);
        virtual double visitSince(const PNode& node);
        virtual double visitAbs(const PNode& node);
        virtual double visitSqrt(const PNode& node);
        virtual double visitExp(const PNode& node);
        virtual double visitPow(const PNode& node);
        virtual double visitLog(const PNode& node);
        virtual double visitLn(const PNode& node);
        virtual double visitAddition(const PNode& node);
        virtual double visitSubtraction(const PNode& node);
        virtual double visitMultiplication (const PNode& node);
        virtual double visitDivision(const PNode& node);
        virtual double visitNegate(const PNode& node);
        virtual double visitRise(const PNode& node);
        virtual double visitFall(const PNode& node);
        virtual double visitPrevious(const PNode& node);
        virtual double visitStrongPrevious(const PNode& node);
        virtual double visitNext(const PNode& node);
        virtual double visitStrongNext(const PNode& node);
    };
}