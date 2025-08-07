#include <ast/visitor/stl/ast_visitor.hpp>

#include <node/stl/timed_always.hpp>
#include <node/stl/timed_eventually.hpp>
#include <node/stl/timed_historically.hpp>
#include <node/stl/timed_once.hpp>
#include <node/stl/timed_precedes.hpp>
#include <node/stl/timed_since.hpp>
#include <node/stl/timed_until.hpp>

#include <iostream>
#include <ast/visitor/ltl/ast_visitor.hpp>
#include <node/abstract_node.hpp>

using namespace stl_library;

StlAstVisitor::StlAstVisitor() : LtlAstVisitor() {
}

double StlAstVisitor::visit(const PNode& node) {
    //std::cout << "visited node " << node->getName() << "\n";
    double result = 0;

    if (std::dynamic_pointer_cast<TimedAlwaysNode>(node)) {
        result = visitTimedAlways(node);
    }
    else if (std::dynamic_pointer_cast<TimedEventuallyNode>(node)) {
        result = visitTimedEventually(node);
    }
    else if (std::dynamic_pointer_cast<TimedHistoricallyNode>(node)) {
        result = visitTimedHistorically(node);
    }
    else if (std::dynamic_pointer_cast<TimedOnceNode>(node)) {
        result = visitTimedOnce(node);
    }
    else if (std::dynamic_pointer_cast<TimedPrecedesNode>(node)) {
        result = visitTimedPrecedes(node);
    }
    else if (std::dynamic_pointer_cast<TimedSinceNode>(node)) {
        result = visitTimedSince(node);
    }
    else if (std::dynamic_pointer_cast<TimedUntilNode>(node)) {
        result = visitTimedUntil(node);
    }
    else {
        result = LtlAstVisitor::visit(node);
    }

    return result;
}

double StlAstVisitor::visitTimedAlways(const PNode& node) { return this->visitChildren(node); }
double StlAstVisitor::visitTimedEventually(const PNode& node) { return this->visitChildren(node); }
double StlAstVisitor::visitTimedOnce(const PNode& node) { return this->visitChildren(node); }
double StlAstVisitor::visitTimedHistorically(const PNode& node) { return this->visitChildren(node); }
double StlAstVisitor::visitTimedPrecedes(const PNode& node) { return this->visitChildren(node); }
double StlAstVisitor::visitTimedSince(const PNode& node) { return this->visitChildren(node); }
double StlAstVisitor::visitTimedUntil(const PNode& node) { return this->visitChildren(node); }


/**
from rtamt.exception.exception import RTAMTException
from rtamt.syntax.node.stl.timed_precedes import TimedPrecedes

from rtamt.syntax.ast.visitor.ltl.ast_visitor import LtlAstVisitor

#from rtamt.syntax.node.stl.timed_precedes import TimedPrecedes
from rtamt.syntax.node.stl.timed_since import TimedSince
from rtamt.syntax.node.stl.timed_once import TimedOnce
from rtamt.syntax.node.stl.timed_historically import TimedHistorically
from rtamt.syntax.node.stl.timed_eventually import TimedEventually
from rtamt.syntax.node.stl.timed_always import TimedAlways
from rtamt.syntax.node.stl.timed_until import TimedUntil


class StlAstVisitor(LtlAstVisitor):

    def visit(self, node, *args, **kwargs):
        if isinstance(node, TimedUntil):
            result = self.visitTimedUntil(node, *args, **kwargs)
        elif isinstance(node, TimedAlways):
            result = self.visitTimedAlways(node, *args, **kwargs)
        elif isinstance(node, TimedEventually):
            result = self.visitTimedEventually(node, *args, **kwargs)
        elif isinstance(node, TimedSince):
            result = self.visitTimedSince(node, *args, **kwargs)
        elif isinstance(node, TimedOnce):
            result = self.visitTimedOnce(node, *args, **kwargs)
        elif isinstance(node, TimedHistorically):
            result = self.visitTimedHistorically(node, *args, **kwargs)
        elif isinstance(node, TimedPrecedes):
            result = self.visitTimedPrecedes(node, *args, **kwargs)
        else:
            result = super(StlAstVisitor, self).visit(node, *args, **kwargs)

        return result

    def visitTimedPrecedes(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitTimedOnce(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitTimedHistorically(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitTimedSince(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitTimedPrecedes(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitTimedAlways(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitTimedEventually(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitTimedUntil(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def raise_exception(self, text):
        raise RTAMTException(text)

*/