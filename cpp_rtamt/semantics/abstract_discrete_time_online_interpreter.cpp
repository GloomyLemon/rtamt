#include <abstract_discrete_time_online_interpreter.hpp>
#include "discrete_time_interpreter.hpp"
#include "abstract_online_interpreter.hpp"
#include "stl/discrete_time/online/cpp/ast_visitor.hpp"

#include <vector>
#include <node/abstract_node.hpp>

using namespace stl_library;

DiscreteTimeOnlineInterpreter::DiscreteTimeOnlineInterpreter(const PNode& ast_root_node, const AbstractOnlineInterpreter& aoi): AbstractDiscreteTimeInterpreter(), AbstractOnlineInterpreter(ast_root_node), prev_timestamp(-std::numeric_limits<double>::infinity()), operator_visitor(aoi) {
};
DiscreteTimeOnlineInterpreter::DiscreteTimeOnlineInterpreter(const PNode& ast_root_node) : DiscreteTimeOnlineInterpreter(ast_root_node, static_cast<AbstractOnlineInterpreter&>(*this)) {
};

#include <iostream>
double DiscreteTimeOnlineInterpreter::update(double timestamp, const DataSet& dataset)
{
    double scaled_timestamp = this->scale_time(timestamp);
    if (!std::isinf(this->prev_timestamp)) {
        double duration = scaled_timestamp - prev_timestamp;
        this->update_sampling_violation_counter(duration);
    }
    this->prev_timestamp = scaled_timestamp;

    dataset_check(dataset);

    set_variable_to_ast_from_dataset(dataset);

    double result = operator_visitor.visit(ast);

    return result;

};

void DiscreteTimeOnlineInterpreter::reset() {
    DiscreteTimeResetVisitor reset_visitor;
    reset_visitor.visit(ast);
    this->prev_timestamp = -std::numeric_limits<double>::infinity();
};


void DiscreteTimeOnlineInterpreter::set_variable_to_ast_from_dataset(const DataSet& p_dataset) {

    for (auto& entry : p_dataset) {
        var_object_dict[entry.first] = entry.second;

        // Example: do something with each signal
        // std::cout << signalName << " has " << samples.size() << " samples\n";
    }

};

void DiscreteTimeOnlineInterpreter::set_ast(const PNode& n) {
    AbstractOnlineInterpreter::set_ast(n);

    ast = n;
    StlDiscreteTimeOnlineAstVisitor dict_visitor = StlDiscreteTimeOnlineAstVisitor(get_sampling_period());
    dict_visitor.visit(n);
    operations = dict_visitor.getOperations();
}