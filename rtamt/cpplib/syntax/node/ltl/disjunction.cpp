#include <node/ltl/disjunction.hpp>

using namespace stl_library;


DisjunctionNode::DisjunctionNode(const PNode& lchild, const PNode& rchild) : BinaryNode(lchild, rchild) {
    inVars = lchild->getInVars();
    inVars.insert(inVars.end(), rchild->getInVars().begin(), rchild->getInVars().end());
    outVars = rchild->getOutVars();
    outVars.insert(outVars.end(), rchild->getOutVars().begin(), rchild->getOutVars().end());
    name = "( " + lchild->getName() + ") or (" + rchild->getName() + " )";
}


/*
* from rtamt.syntax.node.binary_node import BinaryNode

class Disjunction(BinaryNode):
    """A class for storing STL Or nodes
        Inherits TemporalNode
    """
    def __init__(self, child1, child2):
        """Constructor for Or node

        Parameters:
            child1 : stl.Node
            child2 : stl.Node
        """
        super(Disjunction, self).__init__(child1, child2)

        self.in_vars = child1.in_vars + child2.in_vars
        self.out_vars = child1.out_vars + child2.out_vars

        self.name = '(' + child1.name + ')or(' + child2.name + ')'

*/



