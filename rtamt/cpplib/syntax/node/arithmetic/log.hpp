#ifndef STL_LOG_NODE_H
#define STL_LOG_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>

namespace stl_library {


    class LogNode : public BinaryNode {
    public:
        LogNode(const PNode& lchild, const PNode& rchild);
    };
}

#endif

/*
* from rtamt.syntax.node.binary_node import BinaryNode

class Log(BinaryNode):
    """A class for storing Log nodes
        Inherits Node
    """
    def __init__(self, child1, child2):
        """Constructor for Log node

            Parameters:
                child1 : stl.Node
                child2 : stl.Node
        """
        super(Log, self).__init__(child1, child2)

        self.in_vars = child1.in_vars + child2.in_vars
        self.out_vars = child1.out_vars + child2.out_vars

        self.name = 'log(' + child1.name + ',' + child2.name + ')'



*/