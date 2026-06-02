#pragma once

#include <node/abstract_node.hpp>
#include <ast/visitor/stl/ast_visitor.hpp>
#include <abstract_online_operation.hpp>

#include <map>
#include <utility>

namespace stl_library {

    class StlDiscreteTimeOnlineAstVisitor : public StlAstVisitor {
    private:
        std::vector<std::unique_ptr<AbstractOnlineOperation>> operations;

    public:
        //StlDiscreteTimeOnlineAstVisitor();
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
        double visitTimedHistorically(const PNode& node);
        double visitTimedOnce(const PNode& node);
        double visitTimedPrecedes(const PNode& node);
        double visitTimedSince(const PNode& node);

        std::vector<std::unique_ptr<AbstractOnlineOperation>> getOperations() { return std::move(operations); };
    };
}