#ifndef STL_EVT_NODE_H
#define STL_EVT_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class EventuallyNode : public UnaryNode {
    public:
        EventuallyNode(const PNode& child);
    };
}

#endif
/*
* from rtamt.syntax.node.unary_node import UnaryNode

class Eventually(UnaryNode):
    """A class for storing STL Eventually nodes
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