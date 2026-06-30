#include <abstract_online_interpreter.hpp>

using namespace stl_library;

#include <stl/discrete_time/online/cpp/ast_visitor.hpp>
#include "abstract_interpreter.hpp"

AbstractOnlineInterpreter::AbstractOnlineInterpreter(const PNode& n) : AbstractInterpreter(n) {
    set_ast(n);
}

void AbstractOnlineInterpreter::set_ast(const PNode& n) {
    AbstractInterpreter::set_ast(n);

    ast = n;
    StlDiscreteTimeOnlineAstVisitor dict_visitor = StlDiscreteTimeOnlineAstVisitor();
    dict_visitor.visit(n);
    operations = dict_visitor.getOperations();
}