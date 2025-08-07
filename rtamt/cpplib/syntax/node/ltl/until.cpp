#include <node/ltl/until.hpp>

using namespace stl_library;

UntilNode::UntilNode(const PNode& lchild, const PNode& rchild) {
    inVars = lchild->getInVars();
    inVars.insert(inVars.end(), rchild->getInVars().begin(), rchild->getInVars().end());
    outVars = rchild->getOutVars();
    outVars.insert(outVars.end(), rchild->getOutVars().begin(), rchild->getOutVars().end());
    name = "( " + lchild->getName() + ")until(" + rchild->getName() + " )";
}


/*
* from rtamt.syntax.node.binary_node import BinaryNode

class Until(BinaryNode):
    """
    A class for storing STL Since nodes
    Inherits TemporalNode
    """
    def __init__(self, child1, child2):
        """Constructor for Until node

            Parameters:
                child1 : stl.Node
                child2 : stl.Node
                bound : Interval
        """
        super(Until, self).__init__(child1, child2)

        self.name = '(' + child1.name + ')until(' + child2.name + ')'

        self.in_vars = child1.in_vars + child2.in_vars
        self.out_vars = child1.out_vars + child2.out_vars
*/

