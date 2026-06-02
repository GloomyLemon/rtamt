#include <stl/discrete_time/online/cpp/ast_visitor.hpp>

#include <abstract_online_operation.hpp>

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

// to retrieve the interval
#include <node/stl/timed_historically.hpp>
#include <node/stl/timed_eventually.hpp>
#include <node/stl/timed_once.hpp>
#include <node/stl/timed_since.hpp>
#include <node/stl/timed_until.hpp>
#include <node/stl/timed_precedes.hpp>
#include <node/stl/timed_always.hpp>


#include <memory>
#include <rtamt_stl_library/include/stl_operator_type.h>

using namespace stl_library;

double StlDiscreteTimeOnlineAstVisitor::visitPredicate(const PNode& node) {
    auto pred = std::static_pointer_cast<PredicateNode>(node);

    auto op = std::make_unique<StlPredicateNode>(pred->getOperator());
    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitRise(const PNode& node) {
    auto op = std::make_unique<StlRiseNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitFall(const PNode& node) {
    auto op = std::make_unique<StlFallNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitVariable(const PNode& node) {
    auto op = std::make_unique<StlVarNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitConstant(const PNode& node) {
    auto constant = std::static_pointer_cast<ConstantNode>(node);

    auto op = std::make_unique<StlConstantNode>(constant->getValue());

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitPrevious(const PNode& node) {
    auto op = std::make_unique<StlPreviousNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitNot(const PNode& node) {
    auto op = std::make_unique<StlNotNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitDisjunction(const PNode& node) {
    auto op = std::make_unique<StlCombinatorialBinaryNode>(StlOperatorType::OR);

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitConjunction(const PNode& node) {
    auto op = std::make_unique<StlCombinatorialBinaryNode>(StlOperatorType::AND);

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitImplies(const PNode& node) {
    auto op = std::make_unique<StlCombinatorialBinaryNode>(StlOperatorType::IMPLIES);

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitIff(const PNode& node) {
    auto op = std::make_unique<StlCombinatorialBinaryNode>(StlOperatorType::IFF);

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitXor(const PNode& node) {
    auto op = std::make_unique<StlCombinatorialBinaryNode>(StlOperatorType::XOR);

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}


double StlDiscreteTimeOnlineAstVisitor::visitAddition(const PNode& node) {
    auto op = std::make_unique<StlAdditionNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitSubtraction(const PNode& node) {
    auto op = std::make_unique<StlSubtractionNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitMultiplication(const PNode& node) {
    auto op = std::make_unique<StlMultiplicationNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitDivision(const PNode& node) {
    auto op = std::make_unique<StlDivisionNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitExp(const PNode& node) {
    auto op = std::make_unique<StlExpNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitLn(const PNode& node) {
    auto op = std::make_unique<StlLnNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitLog(const PNode& node) {
    auto op = std::make_unique<StlLogNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitPow(const PNode& node) {
    auto op = std::make_unique<StlPowNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitSqrt(const PNode& node) {
    auto op = std::make_unique<StlSqrtNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitNegate(const PNode& node) {
    auto op = std::make_unique<StlNegateNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitAbs(const PNode& node) {
    auto op = std::make_unique<StlAbsNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitEventually(const PNode& node) {
    auto op = std::make_unique<StlEventuallyNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitAlways(const PNode& node) {
    auto op = std::make_unique<StlAlwaysNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitOnce(const PNode& node) {
    auto op = std::make_unique<StlOnceNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitHistorically(const PNode& node) {
    auto op = std::make_unique<StlHistoricallyNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitSince(const PNode& node) {
    auto op = std::make_unique<StlSinceNode>();

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitTimedSince(const PNode& node) {
    auto tn = std::dynamic_pointer_cast<TimedSinceNode>(node);

    auto op = std::make_unique<StlSinceBoundedNode>(
        tn->getInterval().getBegin(),
        tn->getInterval().getEnd()
    );

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}

double StlDiscreteTimeOnlineAstVisitor::visitTimedOnce(const PNode& node) {
    auto tn = std::dynamic_pointer_cast<TimedOnceNode>(node);

    auto op = std::make_unique<StlOnceBoundedNode>(
        tn->getInterval().getBegin(),
        tn->getInterval().getEnd()
    );

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}


double StlDiscreteTimeOnlineAstVisitor::visitTimedHistorically(const PNode& node) {
    auto tn = std::dynamic_pointer_cast<TimedHistoricallyNode>(node);

    auto op = std::make_unique<StlHistoricallyBoundedNode>(
        tn->getInterval().getBegin(),
        tn->getInterval().getEnd()
    );

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}


double StlDiscreteTimeOnlineAstVisitor::visitTimedPrecedes(const PNode& node) {
    auto tn = std::dynamic_pointer_cast<TimedPrecedesNode>(node);

    auto op = std::make_unique<StlPrecedesBoundedNode>(
        tn->getInterval().getBegin(),
        tn->getInterval().getEnd()
    );

    node->setOperation(op.get());
    operations.push_back(std::move(op));

    return visitChildren(node);
}
