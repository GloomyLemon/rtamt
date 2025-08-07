#ifndef STL_NEXT_NODE_H
#define STL_NEXT_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class NextNode : public UnaryNode {
    public:
        NextNode(const PNode& child);
    };
}

#endif

/*
* from rtamt.syntax.node.unary_node import UnaryNode

class Next(UnaryNode):
    """A class for storing STL Next nodes
        Inherits Node
    """
    def __init__(self, child):
        """Constructor for Next node

            Parameters:
                child : stl.Node
        """
        super(Next, self).__init__(child)
        self.in_vars = child.in_vars
        self.out_vars = child.out_vars

        self.name = 'next(' + child.name + ')'
*/