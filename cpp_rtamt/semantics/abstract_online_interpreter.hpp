#pragma once

#include <node/abstract_node.hpp>
#include <abstract_interpreter.hpp>
#include <abstract_online_operation.hpp>

#include <unordered_map>
#include <map>

namespace stl_library {

    class AbstractOnlineInterpreter : public AbstractInterpreter {
    protected:
        std::vector<std::unique_ptr<AbstractOnlineOperation>> operations;
        std::unordered_map<std::string, double> var_object_dict;

        PNode ast;

    public:
        AbstractOnlineInterpreter() = delete;
        AbstractOnlineInterpreter(const PNode& n);


        const std::unordered_map<std::string, double>& get_variable_dict() const { return var_object_dict; }

        // safe const lookup: avoid operator[] (non-const) and unnecessary copies
        double get_variable_value_from_dict(const std::string& expr_name) const {
            auto it = var_object_dict.find(expr_name);
            return (it != var_object_dict.end()) ? it->second : 0;
        }

        void set_ast(const PNode& n);
    };

}