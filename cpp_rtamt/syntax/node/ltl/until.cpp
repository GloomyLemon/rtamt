#include <node/ltl/until.hpp>

using namespace stl_library;

UntilNode::UntilNode(const PNode& lchild, const PNode& rchild) {
    inVars = lchild->getInVars();
    inVars.insert(inVars.end(), rchild->getInVars().begin(), rchild->getInVars().end());
    outVars = rchild->getOutVars();
    outVars.insert(outVars.end(), rchild->getOutVars().begin(), rchild->getOutVars().end());
    name = "( " + lchild->getName() + ")until(" + rchild->getName() + " )";
}

