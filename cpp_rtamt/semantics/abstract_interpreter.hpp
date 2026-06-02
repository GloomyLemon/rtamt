#pragma once

#include <node/abstract_node.hpp>

namespace stl_library {

    class AbstractInterpreter {
    private:
        PNode ast;

    public:
        AbstractInterpreter() = delete;
        AbstractInterpreter(const PNode& n);
        bool exist_ast();
        void set_ast(const PNode& n);
    };

}