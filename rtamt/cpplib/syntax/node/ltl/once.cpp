#include <node/ltl/once.hpp>

using namespace stl_library;

OnceNode::OnceNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "O( " + child->getName() + " )";
}

/*
* from rtamt.syntax.node.unary_node import UnaryNode

class Once(UnaryNode):
    """A class for storing STL Once nodes
                Inherits TemporalNode
    """
    def __init__(self, child):
        """Constructor for Once node

        Parameters:
            child : stl.Node
            bound : Interval
        """

        super(Once, self).__init__(child)
        self.in_vars = child.in_vars
        self.out_vars = child.out_vars
        self.name = 'once(' + child.name + ')'
*/



