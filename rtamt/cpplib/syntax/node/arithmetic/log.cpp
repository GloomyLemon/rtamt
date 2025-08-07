#include <node/arithmetic/log.hpp>

using namespace stl_library;

LogNode::LogNode(const PNode& lchild, const PNode& rchild) : BinaryNode(lchild, rchild) {
    inVars = lchild->getInVars();
    inVars.insert(inVars.end(), rchild->getInVars().begin(), rchild->getInVars().end());
    outVars = rchild->getOutVars();
    outVars.insert(outVars.end(), rchild->getOutVars().begin(), rchild->getOutVars().end());
    name = "log( " + lchild->getName() + ", " + rchild->getName() + " )";
}


/*
* from rtamt.syntax.node.binary_node import BinaryNode

class Log(BinaryNode):
    """A class for storing Log nodes
        Inherits Node
    """
    def __init__(self, child1, child2):
        """Constructor for Log node

            Parameters:
                child1 : stl.Node
                child2 : stl.Node
        """
        super(Log, self).__init__(child1, child2)

        self.in_vars = child1.in_vars + child2.in_vars
        self.out_vars = child1.out_vars + child2.out_vars

        self.name = 'log(' + child1.name + ',' + child2.name + ')'



*/