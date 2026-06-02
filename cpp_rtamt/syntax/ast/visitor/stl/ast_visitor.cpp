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

    switch (node->getType()) {

    case AbstractNode::NodeType::TimedAlways:
        return visitTimedAlways(node);

    case AbstractNode::NodeType::TimedEventually:
        return visitTimedEventually(node);

    case AbstractNode::NodeType::TimedHistorically:
        return visitTimedHistorically(node);

    case AbstractNode::NodeType::TimedOnce:
        return visitTimedOnce(node);

    case AbstractNode::NodeType::TimedPrecedes:
        return visitTimedPrecedes(node);

    case AbstractNode::NodeType::TimedSince:
        return visitTimedSince(node);

    case AbstractNode::NodeType::TimedUntil:
        return visitTimedUntil(node);

    default:
        return LtlAstVisitor::visit(node);
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
