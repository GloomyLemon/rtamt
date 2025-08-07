#include <node/ltl/always.hpp>

using namespace stl_library;

AlwaysNode::AlwaysNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "G( " + child->getName() + " )";
}

/*
* from rtamt.syntax.node.unary_node import UnaryNode

class Always(UnaryNode):
    """A class for storing STL Always nodes
        Inherits TemporalNode
    """

    def __init__(self, child):
        """Constructor for Always

        Parameters:
            child : stl.Node
            bound : Interval
        """
        super(Always, self).__init__(child)

        self.in_vars = child.in_vars
        self.out_vars = child.out_vars

        self.name = 'always(' + child.name + ')'
*/






