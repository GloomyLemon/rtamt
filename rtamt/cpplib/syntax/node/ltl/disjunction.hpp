#ifndef STL_DISJ_NODE_H
#define STL_DISJ_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {


    class DisjunctionNode : public BinaryNode {
    public:
        DisjunctionNode(const PNode& lchild, const PNode& rchild);
    };
}

#endif

/*
* from rtamt.syntax.node.binary_node import BinaryNode

class Disjunction(BinaryNode):
    """A class for storing STL Or nodes
        Inherits TemporalNode
    """
    def __init__(self, child1, child2):
        """Constructor for Or node

        Parameters:
            child1 : stl.Node
            child2 : stl.Node
        """
        super(Disjunction, self).__init__(child1, child2)

        self.in_vars = child1.in_vars + child2.in_vars
        self.out_vars = child1.out_vars + child2.out_vars

        self.name = '(' + child1.name + ')or(' + child2.name + ')'

*/



