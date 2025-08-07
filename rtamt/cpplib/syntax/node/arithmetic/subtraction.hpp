#ifndef STL_SUB_NODE_H
#define STL_SUB_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {


    class SubtractionNode : public BinaryNode {
    public:
        SubtractionNode(const PNode& lchild, const PNode& rchild);
    };
}

#endif

/*
* from rtamt.syntax.node.binary_node import BinaryNode

class Subtraction(BinaryNode):
    """A class for storing STL Subtraction nodes
        Inherits Node
    """
    def __init__(self, child1, child2):
        """Constructor for Subtraction node

            Parameters:
                child1 : stl.Node
                child2 : stl.Node
        """
        super(Subtraction, self).__init__(child1, child2)


        self.in_vars = child1.in_vars + child2.in_vars
        self.out_vars = child1.out_vars + child2.out_vars

        self.name = '(' + child1.name + ')-(' + child2.name + ')'
*/

