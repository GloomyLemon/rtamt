#ifndef STL_SINCE_NODE_H
#define STL_SINCE_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {


    class SinceNode : public BinaryNode {
    public:
        SinceNode(const PNode& lchild, const PNode& rchild);
    };
}

#endif

/*
* from rtamt.syntax.node.binary_node import BinaryNode

class Since(BinaryNode):
    """A class for storing STL Since nodes
                Inherits TemporalNode
    """
    def __init__(self, child1, child2):
        """Constructor for Since node

            Parameters:
                child1 : stl.Node
                child2 : stl.Node
        """

        super(Since, self).__init__(child1, child2)

        self.in_vars = child1.in_vars + child2.in_vars
        self.out_vars = child1.out_vars + child2.out_vars
        self.name = '(' + child1.name + ')since(' + child2.name + ')'
*/


