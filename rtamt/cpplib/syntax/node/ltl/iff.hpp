#ifndef STL_IFF_NODE_H
#define STL_IFF_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {


    class IffNode : public BinaryNode {
    public:
        IffNode(const PNode& lchild, const PNode& rchild);
    };
}

#endif

/*
* from rtamt.syntax.node.binary_node import BinaryNode


class Iff(BinaryNode):
    """A class for storing STL Iff nodes
        Inherits TemporalNode
    """
    def __init__(self, child1, child2):
        """Constructor for Iff node

        Parameters:
            child1 : stl.Node
            child2 : stl.Node
        """
        super(Iff, self).__init__(child1, child2)

        self.in_vars = child1.in_vars + child2.in_vars
        self.out_vars = child1.out_vars + child2.out_vars

        self.name = '(' + child1.name + ')<->(' + child2.name + ')'
*/




