#include <node/ltl/eventually.hpp>

using namespace stl_library;

EventuallyNode::EventuallyNode(const PNode& child) : UnaryNode(child) {
    inVars = child->getInVars();
    outVars = child->getOutVars();
    name = "F( " + child->getName() + " )";
}

/*
* from rtamt.syntax.node.unar
    """A class for storing STL Eventy_node import UnaryNode

class Eventually(UnaryNode):ually nodes
            Inherits TemporalNode
    """
    def __init__(self, child):
        """Constructor for Eventually node

        Parameters:
            child : stl.Node
            bound : Interval
        """
        super(Eventually, self).__init__(child)
        self.in_vars = child.in_vars
        self.out_vars = child.out_vars
        self.name = 'eventually(' + child.name + ')'


*/