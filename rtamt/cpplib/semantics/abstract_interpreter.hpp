#pragma once

#include <node/abstract_node.hpp>

#include <map>
#include <vector>
#include <string>
#include <utility>

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

/*
* # -*- coding: utf-8 -*-
"""
Created on Mon Sep 23 2019

@author: Dejan Nickovic
"""
from abc import ABCMeta

from rtamt.exception.exception import RTAMTException

class AbstractInterpreter(object):
    """
    Abstract Operation: template for any monitoring operation
    """
    __metaclass__ = ABCMeta
    NOT_IMPLEMENTED = "You should implement this."

    def exist_ast(self):
        if self.ast is None:
            raise RTAMTException('ast is empty')
        return

    def set_ast(self, ast):
        self.ast = ast
        return

*/