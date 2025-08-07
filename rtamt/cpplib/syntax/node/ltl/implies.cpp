#include <node/ltl/implies.hpp>

using namespace stl_library;

ImpliesNode::ImpliesNode(const PNode& lchild, const PNode& rchild) : BinaryNode(lchild, rchild) {
    inVars = lchild->getInVars();
    inVars.insert(inVars.end(), rchild->getInVars().begin(), rchild->getInVars().end());
    outVars = rchild->getOutVars();
    outVars.insert(outVars.end(), rchild->getOutVars().begin(), rchild->getOutVars().end());
    name = "( " + lchild->getName() + ")->(" + rchild->getName() + " )";
}


/*
* from rtamt.syntax.node.binary_node import BinaryNode

class Implies(BinaryNode):
    """A class for storing STL Implies nodes
        Inherits TemporalNode
    """
    def __init__(self, child1, child2):
        """Constructor for Implies node

        Parameters:
            child1 : stl.Node
            child2 : stl.Node
        """
        super(Implies, self).__init__(child1, child2)

        self.in_vars = child1.in_vars + child2.in_vars
        self.out_vars = child1.out_vars + child2.out_vars

        self.name = '(' + child1.name + ')->(' + child2.name + ')'
*/



