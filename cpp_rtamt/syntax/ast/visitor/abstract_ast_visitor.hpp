#ifndef STL_ABSTRACT_AST_VISITOR_H
#define STL_ABSTRACT_AST_VISITOR_H

#include <node/abstract_node.hpp>

namespace stl_library {

    class AbstractAstVisitor{
        public:
            AbstractAstVisitor();
            virtual double visit(const PNode& node) = 0;
            double visitChildren(const PNode& node);
    //		double visitAst(AST ast);
    //		double visitSpec(Spec spec);
            double visitUnary(const PNode& node);
            double visitBinary(const PNode& node);
            double visitLeaf(const PNode& node);
       
    };

} // namespace stl_library


#endif /* STL_ABSTRACT_AST_VISITOR_H */