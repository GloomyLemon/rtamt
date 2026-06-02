#pragma once

#include <ast/visitor/ltl/ast_visitor.hpp>

namespace stl_library {

    class StlAstVisitor : public LtlAstVisitor {
    private:

    public:
        StlAstVisitor();
        double visit(const PNode& node) override;
        virtual double visitTimedAlways(const PNode& node);
        virtual double visitTimedEventually(const PNode& node);
        virtual double visitTimedHistorically(const PNode& node);
        virtual double visitTimedOnce(const PNode& node);
        virtual double visitTimedPrecedes(const PNode& node);
        virtual double visitTimedSince(const PNode& node);
        virtual double visitTimedUntil(const PNode& node);
    };
}