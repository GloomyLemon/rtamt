#pragma once

#include <discrete_time_interpreter.hpp>
#include <abstract_online_interpreter.hpp>

#include <ast/visitor/stl/ast_visitor.hpp>

#include <iostream>
#include "abstract_online_operation.hpp"
#include <node/abstract_node.hpp>
#include "time_interpreter.hpp"

namespace stl_library {

    class DiscreteTimeOperatorVisitor : public StlAstVisitor {
    private:
        const AbstractOnlineInterpreter& interpreter;
    public:
        //DiscreteTimeOperatorVisitor() = delete;
        DiscreteTimeOperatorVisitor(const AbstractOnlineInterpreter& i) : interpreter(i) {}
        double visitPredicate(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());

            double left_result = visit(node->getChildren()[0]);
            double right_result = visit(node->getChildren()[1]);

            return op->update(left_result, right_result);
        }



        double visitVariable(const PNode& node) {
            double result = interpreter.get_variable_value_from_dict(node->getName());
            return result;
        }
        double visitConstant(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double result = op->update();
            return result;
        }
        double visitNot(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitDisjunction(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double left_result = visit(node->getChildren()[0]);
            double right_result = visit(node->getChildren()[1]);
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitConjunction(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double left_result = visit(node->getChildren()[0]);
            double right_result = visit(node->getChildren()[1]);
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitImplies(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double left_result = visit(node->getChildren()[0]);
            double right_result = visit(node->getChildren()[1]);
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitIff(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double left_result = visit(node->getChildren()[0]);
            double right_result = visit(node->getChildren()[1]);
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitXor(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double left_result = visit(node->getChildren()[0]);
            double right_result = visit(node->getChildren()[1]);
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitEventually(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitAlways(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitUntil(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double left_result = visit(node->getChildren()[0]);
            double right_result = visit(node->getChildren()[1]);
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitOnce(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitHistorically(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitSince(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double left_result = visit(node->getChildren()[0]);
            double right_result = visit(node->getChildren()[1]);
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitAbs(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitSqrt(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitExp(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitPow(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double left_result = visit(node->getChildren()[0]);
            double right_result = visit(node->getChildren()[1]);
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitLog(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double left_result = visit(node->getChildren()[0]);
            double right_result = visit(node->getChildren()[1]);
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitLn(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitAddition(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double left_result = visit(node->getChildren()[0]);
            double right_result = visit(node->getChildren()[1]);
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitSubtraction(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double left_result = visit(node->getChildren()[0]);
            double right_result = visit(node->getChildren()[1]);
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitMultiplication(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double left_result = visit(node->getChildren()[0]);
            double right_result = visit(node->getChildren()[1]);
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitDivision(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double left_result = visit(node->getChildren()[0]);
            double right_result = visit(node->getChildren()[1]);
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitNegate(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitRise(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitFall(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitPrevious(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitStrongPrevious(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitNext(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitStrongNext(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitTimedAlways(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitTimedEventually(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitTimedHistorically(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitTimedOnce(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double child_result = visit(node->getChildren()[0]);
            double result = op->update(child_result);
            return result;
        }
        double visitTimedPrecedes(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double left_result = visit(node->getChildren()[0]);
            double right_result = visit(node->getChildren()[1]);
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitTimedSince(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double left_result = visit(node->getChildren()[0]);
            double right_result = visit(node->getChildren()[1]);
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitTimedUntil(const PNode& node) {
            auto* op = static_cast<AbstractOnlineOperation*>(node->getOperation());
            double left_result = visit(node->getChildren()[0]);
            double right_result = visit(node->getChildren()[1]);
            double result = op->update(left_result, right_result);
            return result;
        }
    };

    class DiscreteTimeOnlineInterpreter : public AbstractDiscreteTimeInterpreter, public AbstractOnlineInterpreter {
    protected:
        //DiscreteTimeOperatorVisitor operator_visitor;

    public:
        DiscreteTimeOperatorVisitor operator_visitor;
        DiscreteTimeOnlineInterpreter() = delete;
        DiscreteTimeOnlineInterpreter(const PNode& ast_root_node);
        DiscreteTimeOnlineInterpreter(const PNode& ast_root_node, const AbstractOnlineInterpreter& aoi);
        double update(double timestamp, const DataSet& dataset);
        void reset();
        void set_variable_to_ast_from_dataset(const DataSet& p_dataset) override;
        //bool dataset_check(DataSet& p_dataset) override;
        //void set_variable_to_ast_from_dataset() override;
    };

    
    
}