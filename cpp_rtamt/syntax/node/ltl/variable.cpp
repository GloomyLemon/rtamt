#include <node/ltl/variable.hpp>

using namespace stl_library;

VariableNode::VariableNode(std::string var) {
    inVars.push_back(var);
    outVars.push_back(var);
    name = var;
}