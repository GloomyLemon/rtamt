#include <node/ltl/predicate.hpp>

using namespace stl_library;

        PredicateNode::PredicateNode(const PNode& lchild, const PNode& rchild, OperatorType oper) : BinaryNode(lchild, rchild), op(oper) {
            inVars = lchild->getInVars();
            inVars.insert(inVars.end(), rchild->getInVars().begin(), rchild->getInVars().end());
            outVars = rchild->getOutVars();
            outVars.insert(outVars.end(), rchild->getOutVars().begin(), rchild->getOutVars().end());
            name = "( " + lchild->getName() + ") " + getOperatorString() + " (" + rchild->getName() + " )";
        }
