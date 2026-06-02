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