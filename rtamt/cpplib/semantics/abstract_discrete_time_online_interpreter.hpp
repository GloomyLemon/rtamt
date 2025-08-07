#pragma once

#include <discrete_time_interpreter.hpp>
#include <abstract_online_interpreter.hpp>

#include <ast/visitor/stl/ast_visitor.hpp>

#include <iostream>
#include "abstract_online_operation.hpp"

namespace stl_library {

    class DiscreteTimeOperatorVisitor : public StlAstVisitor {
    private:
        const AbstractOnlineInterpreter& interpreter;
    public:
        //DiscreteTimeOperatorVisitor() = delete;
        DiscreteTimeOperatorVisitor(const AbstractOnlineInterpreter& i) : interpreter(i) {}
        double visitPredicate(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double left_result = visit(node->getChildren().at(0));
            double right_result = visit(node->getChildren().at(1));
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitVariable(const PNode& node) {
            double result = interpreter.get_variable_value_from_dict(node->getName());
            return result;
        }
        double visitConstant(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double result = op->update();
            return result;
        }
        double visitNot(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitDisjunction(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double left_result = visit(node->getChildren().at(0));
            double right_result = visit(node->getChildren().at(1));
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitConjunction(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double left_result = visit(node->getChildren().at(0));
            double right_result = visit(node->getChildren().at(1));
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitImplies(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double left_result = visit(node->getChildren().at(0));
            double right_result = visit(node->getChildren().at(1));
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitIff(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double left_result = visit(node->getChildren().at(0));
            double right_result = visit(node->getChildren().at(1));
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitXor(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double left_result = visit(node->getChildren().at(0));
            double right_result = visit(node->getChildren().at(1));
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitEventually(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitAlways(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitUntil(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double left_result = visit(node->getChildren().at(0));
            double right_result = visit(node->getChildren().at(1));
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitOnce(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitHistorically(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitSince(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double left_result = visit(node->getChildren().at(0));
            double right_result = visit(node->getChildren().at(1));
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitAbs(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitSqrt(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitExp(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitPow(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double left_result = visit(node->getChildren().at(0));
            double right_result = visit(node->getChildren().at(1));
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitLog(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double left_result = visit(node->getChildren().at(0));
            double right_result = visit(node->getChildren().at(1));
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitLn(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitAddition(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double left_result = visit(node->getChildren().at(0));
            double right_result = visit(node->getChildren().at(1));
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitSubtraction(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double left_result = visit(node->getChildren().at(0));
            double right_result = visit(node->getChildren().at(1));
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitMultiplication(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double left_result = visit(node->getChildren().at(0));
            double right_result = visit(node->getChildren().at(1));
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitDivision(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double left_result = visit(node->getChildren().at(0));
            double right_result = visit(node->getChildren().at(1));
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitNegate(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitRise(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitFall(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitPrevious(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitStrongPrevious(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitNext(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitStrongNext(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitTimedAlways(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitTimedEventually(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitTimedHistorically(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitTimedOnce(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitTimedPrecedes(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double child_result = visit(node->getChildren().at(0));
            double result = op->update(child_result);
            return result;
        }
        double visitTimedSince(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double left_result = visit(node->getChildren().at(0));
            double right_result = visit(node->getChildren().at(1));
            double result = op->update(left_result, right_result);
            return result;
        }
        double visitTimedUntil(const PNode& node) {
            POperation op = interpreter.get_operator_from_dict(node->getName());
            double left_result = visit(node->getChildren().at(0));
            double right_result = visit(node->getChildren().at(1));
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
        double update(double timestamp, DataSet dataset);
        void reset();
        void set_variable_to_ast_from_dataset(const DataSet& p_dataset) override;
        //bool dataset_check(DataSet& p_dataset) override;
        //void set_variable_to_ast_from_dataset() override;
    };

    
    
}

/*
import operator

from rtamt.semantics.stl.dense_time.online.variable_operation import VariableOperation
from rtamt.syntax.ast.visitor.abstract_ast_visitor import AbstractAstVisitor
from rtamt.semantics.abstract_online_interpreter import AbstractOnlineInterpreter, AbstractOnlineUpdateVisitor, AbstractOnlineResetVisitor
from rtamt.semantics.discrete_time_interpreter import DiscreteTimeInterpreter

from rtamt.exception.exception import RTAMTException

class AbstractDiscreteTimeOnlineInterpreter(AbstractOnlineInterpreter, DiscreteTimeInterpreter):

    def __init__(self):
        super(AbstractDiscreteTimeOnlineInterpreter, self).__init__()
        self.updateVisitor = DiscreteTimeOnlineUpdateVisitor()
        self.resetVisitor = AbstractOnlineResetVisitor()
        return

    # timestamp - float
    # inputs - list of [var name, var value] pairs
    # Example:
    # update(1, [['a', 2.2], ['b', 3.3]])
    # TODO merge dense and discrete into update AbstractOnlineInterpreter
    def update(self, timestamp, dataset):
        # check ast exists
        self.exist_ast()

        # update the value of every input variable
        self.set_variable_to_ast_from_dataset(dataset)

        # evaluate spec forest
        rob = self.updateVisitor.visitAst(self.ast, self.online_operator_dict, self.ast.var_object_dict)
        rob = rob[len(rob) - 1]
        self.ast.results = self.updateVisitor.results


        out = self.ast.var_object_dict[self.ast.out_var]
        if self.ast.out_var_field:
            setattr(out, self.ast.out_var_field, rob)


        # Check if the difference between two consecutive timestamps is between
        # the accepted tolerance - if not, increase the violation counter
        if self.update_counter > 0:
            duration = (timestamp - self.previous_time) * self.normalize
            self.update_sampling_violation_counter(duration)

        # update time stamp and update counter
        self.previous_time = timestamp
        self.update_counter = self.update_counter + 1

        return rob

    def reset(self):
        super(AbstractDiscreteTimeOnlineInterpreter, self).reset()

        self.update_counter = int(0)
        self.previous_time = float(0.0)
        self.sampling_violation_counter = int(0)
        return

    def set_variable_to_ast_from_dataset(self, dataset):
        for data in dataset:
            var_name = data[0]
            var_value = data[1]
            if data[0] in self.ast.free_vars:
                self.ast.var_object_dict[var_name] = var_value
                self.online_operator_dict[var_name].sample = var_value

    @property
    def update_counter(self):
        return self.__update_counter

    @update_counter.setter
    def update_counter(self, update_counter):
        self.__update_counter = update_counter


class DiscreteTimeOnlineUpdateVisitor(AbstractOnlineUpdateVisitor):
    def visitVariable(self, node, online_operator_dict, var_object_dict):
        var = var_object_dict[node.var]
        if node.field:  #TODO Tom did not understand this line.
            sample_return = operator.attrgetter(node.field)(var)
        else:
            sample_return = var
        return sample_return

    def visitConstant(self, node, online_operator_dict, var_object_dict):
        return node.val


def discrete_time_online_interpreter_factory(AstVisitor):
    if not issubclass(AstVisitor, AbstractAstVisitor):  # type check
        raise RTAMTException('{} is not RTAMT AST visitor'.format(AstVisitor.__name__))

    class DiscreteTimeOnlineInterpreter(AbstractDiscreteTimeOnlineInterpreter, AstVisitor):
        def __init__(self, *args, **kwargs):
            super(DiscreteTimeOnlineInterpreter, self).__init__(*args, **kwargs)

    return DiscreteTimeOnlineInterpreter
*/