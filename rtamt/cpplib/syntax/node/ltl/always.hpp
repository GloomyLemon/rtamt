#ifndef STL_ALW_NODE_H
#define STL_ALW_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class AlwaysNode : public UnaryNode {
    public:
        AlwaysNode(const PNode& child);
    };
}

#endif

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






