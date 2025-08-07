#ifndef STL_ONCE_NODE_H
#define STL_ONCE_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class OnceNode : public UnaryNode {
    public:
        OnceNode(const PNode& child);
    };
}

#endif

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



