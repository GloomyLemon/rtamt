#ifndef STL_NOT_NODE_H
#define STL_NOT_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class NotNode : public UnaryNode {
    public:
        NotNode(const PNode& child);
    };
}

#endif

/*
* from rtamt.syntax.node.unary_node import UnaryNode

class Neg(UnaryNode):
    """A class for storing STL Neg nodes
        Inherits Node
    """
    def __init__(self, child):
        """Constructor for Neg node

            Parameters:
                child : stl.Node
        """
        super(Neg, self).__init__(child)
        self.add_child(child)
        self.in_vars = child.in_vars
        self.out_vars = child.out_vars

        self.name = 'not(' + child.name + ')'





*/
