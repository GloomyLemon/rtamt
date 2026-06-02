#include <abstract_discrete_time_online_interpreter.hpp>
#include "discrete_time_interpreter.hpp"
#include "abstract_online_interpreter.hpp"

#include <vector>
#include <node/abstract_node.hpp>

using namespace stl_library;

DiscreteTimeOnlineInterpreter::DiscreteTimeOnlineInterpreter(const PNode& ast_root_node, const AbstractOnlineInterpreter& aoi): AbstractDiscreteTimeInterpreter(), AbstractOnlineInterpreter(ast_root_node), operator_visitor(aoi) {
};
DiscreteTimeOnlineInterpreter::DiscreteTimeOnlineInterpreter(const PNode& ast_root_node) : DiscreteTimeOnlineInterpreter(ast_root_node, static_cast<AbstractOnlineInterpreter&>(*this)) {
};

double DiscreteTimeOnlineInterpreter::update(double timestamp, const DataSet& dataset)
{
    dataset_check(dataset);

    set_variable_to_ast_from_dataset(dataset);

    double result = operator_visitor.visit(ast);

    return result;

};


void DiscreteTimeOnlineInterpreter::reset() {};


void DiscreteTimeOnlineInterpreter::set_variable_to_ast_from_dataset(const DataSet& p_dataset) {

    for (auto& entry : p_dataset) {
        var_object_dict[entry.first] = entry.second;

        // Example: do something with each signal
        // std::cout << signalName << " has " << samples.size() << " samples\n";
    }

};