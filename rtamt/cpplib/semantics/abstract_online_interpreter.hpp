#pragma once

#include <node/abstract_node.hpp>
#include <abstract_interpreter.hpp>
#include <abstract_online_operation.hpp>

#include <unordered_map>
#include <map>

namespace stl_library {

    class AbstractOnlineInterpreter : public AbstractInterpreter {
    protected:
        std::unordered_map<std::string, POperation> online_operator_dict;
        std::unordered_map<std::string, double> var_object_dict;

        PNode ast;

    public:
        AbstractOnlineInterpreter() = delete;
        AbstractOnlineInterpreter(const PNode& n);

        const std::unordered_map<std::string, POperation>& get_operator_dict() const { return online_operator_dict; }

        // safe const lookup: avoid operator[] (non-const) and unnecessary copies
        POperation get_operator_from_dict(const std::string& expr_name) const {
            auto it = online_operator_dict.find(expr_name);
            return (it != online_operator_dict.end()) ? it->second : POperation();
        }

        const std::unordered_map<std::string, double>& get_variable_dict() const { return var_object_dict; }

        // safe const lookup: avoid operator[] (non-const) and unnecessary copies
        double get_variable_value_from_dict(const std::string& expr_name) const {
            auto it = var_object_dict.find(expr_name);
            return (it != var_object_dict.end()) ? it->second : 0;
        }

        void set_ast(const PNode& n);
    };

}

/*
* from abc import abstractmethod

from rtamt.syntax.node.ltl.variable import Variable
from rtamt.syntax.node.ltl.constant import Constant

from rtamt.syntax.ast.visitor.abstract_ast_visitor import AbstractAstVisitor
from rtamt.semantics.abstract_interpreter import AbstractInterpreter

class AbstractOnlineInterpreter(AbstractInterpreter):
    def __init__(self):
        super(AbstractOnlineInterpreter, self).__init__()
        return

    def reset(self):
        # reset sub-specs
        for key in self.ast.var_subspec_dict:
            node = self.ast.var_subspec_dict[key]
            self.resetVisitor.visitAst(node, self.online_operator_dict)

        # reset spec
        self.resetVisitor.visitAst(self.ast, self.online_operator_dict)
        return

    def set_ast(self, ast):
        super(AbstractOnlineInterpreter, self).set_ast(ast)

        # init dict of online operators
        self.online_operator_dict = dict()

        self.visitAst(self.ast)

        # construct online_operator_dict for sub-specs
        #for key in self.ast.var_subspec_dict:
        #    node = self.ast.var_subspec_dict[key]
        #    self.visitAst(node)

        # construct online_operator_dict for spec
        #self.visitAst(self.ast)
        return

    @abstractmethod
    def update(self, *args, **kargs):
        raise NotImplementedError(self.NOT_IMPLEMENTED)

class AbstractOnlineResetVisitor(AbstractAstVisitor):
    def visitBinary(self, node, online_operator_dict):
        self.visitChildren(node, online_operator_dict)
        operator = online_operator_dict[node.name]
        operator.reset()
        return

    def visitUnary(self, node, online_operator_dict):
        self.visitChildren(node, online_operator_dict)
        operator = online_operator_dict[node.name]
        operator.reset()
        return

    def visitLeaf(self, node, online_operator_dict):
        pass


class AbstractOnlineUpdateVisitor(AbstractAstVisitor):
    def __init__(self):
        self.results = dict()

    def visitSpec(self, node, online_operator_dict, var_object_dict):
        sample_return = self.visit(node, online_operator_dict, var_object_dict)
        var_object_dict[node] = sample_return  #TODO subspec name is necessary as a key for var_object_dict.
        self.results[node] = sample_return
        return sample_return

    def visitBinary(self, node, online_operator_dict, var_object_dict):
        sample_left  = self.visit(node.children[0], online_operator_dict, var_object_dict)
        sample_right = self.visit(node.children[1], online_operator_dict, var_object_dict)
        operator = online_operator_dict[node.name]
        sample_return = operator.update(sample_left, sample_right)
        self.results[node] = sample_return
        return sample_return

    def visitUnary(self, node, online_operator_dict, var_object_dict):
        sample = self.visit(node.children[0], online_operator_dict, var_object_dict)
        op = online_operator_dict[node.name]
        sample_return = op.update(sample)
        self.results[node] = sample_return
        return sample_return

    def visitLeaf(self, node, online_operator_dict, var_object_dict):
        if isinstance(node, Constant):
            sample_return = self.visitConstant(node, online_operator_dict, var_object_dict)
        elif isinstance(node, Variable):
            sample_return = self.visitVariable(node, online_operator_dict, var_object_dict)
        self.results[node] = sample_return
        return sample_return

*
*/