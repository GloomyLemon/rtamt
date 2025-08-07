#include <ast/visitor/abstract_ast_visitor.hpp>

#include <iostream>

using namespace stl_library;

AbstractAstVisitor::AbstractAstVisitor() {

}

double AbstractAstVisitor::visitChildren(const PNode& node) {
    //std::vector<double> result = std::vector<double>();
    double result = 0;
    for (auto c : node->getChildren()) {
        result = this->visit(c);
    }
    return result;
}

double AbstractAstVisitor::visit(const PNode& node) {
    return visitChildren(node);
}

double AbstractAstVisitor::visitBinary(const PNode& node) {
    return visitChildren(node);
}

double AbstractAstVisitor::visitUnary(const PNode& node) {
    return visitChildren(node);
}

double AbstractAstVisitor::visitLeaf(const PNode& node) {
    return visitChildren(node);
}


/**
from abc import ABCMeta

from rtamt.syntax.node.binary_node import BinaryNode
from rtamt.syntax.node.unary_node import UnaryNode
from rtamt.syntax.node.leaf_node import LeafNode

from rtamt.exception.exception import RTAMTException


class AbstractAstVisitor(object):
    __metaclass__ = ABCMeta

    def visitChildren(self, node, *args, **kwargs):
        result = None
        for nodeChild in node.children:
            result = self.visit(nodeChild, *args, **kwargs)
        return result   # visitChildren returns only last result

    def visit(self, node, *args, **kwargs):
        if isinstance(node, BinaryNode):
            result = self.visitBinary(node, *args, **kwargs)
        elif isinstance(node, UnaryNode):
            result = self.visitUnary(node, *args, **kwargs)
        elif isinstance(node, LeafNode):
            result = self.visitLeaf(node, *args, **kwargs)
        else:
            raise RTAMTException('{} is not RTAMT AST node'.format(node.__class__.__name__))
        return result

    def visitAst(self, ast, *args, **kwargs):
        out = []
        for spec in ast.specs:
            out.append(self.visit(spec, *args, **kwargs))
        return out

    def visitSpec(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitBinary(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitUnary(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

    def visitLeaf(self, node, *args, **kwargs):
        return self.visitChildren(node, *args, **kwargs)

*/