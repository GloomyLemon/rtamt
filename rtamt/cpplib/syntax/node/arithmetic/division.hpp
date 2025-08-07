#ifndef STL_DIV_NODE_H
#define STL_DIV_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {


    class DivisionNode : public BinaryNode {
    public:
        DivisionNode(const PNode& lchild, const PNode& rchild);
    };
}

#endif

/*
* /from rtamt.syntax.node.binary_node import BinaryNode


class Division(BinaryNode):
    """A class for storing STL Division nodes
        Inherits Node
    """
    def __init__(self, child1, child2):
        """Constructor for Division node

            Parameters:
                child1 : stl.Node
                child2 : stl.Node
        """
        super(Division, self).__init__(child1, child2)

        self.in_vars = child1.in_vars + child2.in_vars
        self.out_vars = child1.out_vars + child2.out_vars

        self.name = '(' + child1.name + ')/(' + child2.name + ')'

*/

