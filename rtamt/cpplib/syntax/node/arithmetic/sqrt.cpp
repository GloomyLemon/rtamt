#include <node/arithmetic/sqrt.hpp>

using namespace stl_library;

SqrtNode::SqrtNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "sqrt( " + child->getName() + " )";
}

/*
* from rtamt.syntax.node.unary_node import UnaryNode

class Sqrt(UnaryNode):
    """A class for storing STL Sqrt nodes
        Inherits Node
    """
    def __init__(self, child):
        """Constructor for Sqrt node

            Parameters:
                child : stl.Node
        """
        super(Sqrt, self).__init__(child)

        self.in_vars = child.in_vars
        self.out_vars = child.out_vars

        self.name = 'sqrt(' + child.name + ')'
*/


