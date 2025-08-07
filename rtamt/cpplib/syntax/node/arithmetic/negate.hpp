#ifndef STL_NEG_NODE_H
#define STL_NEG_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>

namespace stl_library {


    class NegateNode : public UnaryNode {
    public:
        NegateNode(const PNode& child);
    };
}

#endif

/*
* from rtamt.syntax.node.unary_node import UnaryNode

class Negate(UnaryNode):
    """A class for storing STL Negate nodes
        Inherits Node
    """
    def __init__(self, child):
        """Constructor for Neg node

            Parameters:
                child : stl.Node
        """
        super(Negate, self).__init__(child)

        self.in_vars = child.in_vars
        self.out_vars = child.out_vars

        self.name = '-(' + child.name + ')'


*/
