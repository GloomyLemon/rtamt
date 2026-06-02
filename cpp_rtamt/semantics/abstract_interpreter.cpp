#include <abstract_interpreter.hpp>

using namespace stl_library;

AbstractInterpreter::AbstractInterpreter(const PNode& n): ast(n) {}
void AbstractInterpreter::set_ast(const PNode& n) {
    ast = n;
}

bool AbstractInterpreter::exist_ast() {
    return ast != nullptr;
}