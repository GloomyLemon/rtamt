#include <node/abstract_node.hpp>


using namespace stl_library;

AbstractNode::AbstractNode() {
    this->name = "";
    this->inVars = std::vector<std::string>();
    this->outVars = std::vector<std::string>();
    this->children = std::vector<PNode>();
    //this->node = NULL;
}

void AbstractNode::add_child(const PNode &child) {
    this->children.push_back(child);
}


void AbstractNode::setChildren(const std::vector<PNode> &children) {
    this->children = children;
}

void AbstractNode::setInVars(const std::vector<std::string> &vars) {
    this->inVars = vars;
}

void AbstractNode::setOutVars(const std::vector<std::string> &vars) {
    this->outVars = vars;
}

void AbstractNode::setName(std::string name) {
    this->name = name;
}

//void AbstractNode::setNode(AbstractNode* node) {
//    this->node = node;
//}

void AbstractNode::accept(AbstractAstVisitor &visitor) {
    for (auto const& c : this->children) {
        c->accept(visitor);
    }
}


/**

from abc import ABCMeta

class AbstractNode:
    """
    Abstract Node: tree-like data structure containing
    arbitrary specifications
    """
    __metaclass__ = ABCMeta

    def __init__(self):
        self.in_vars = []
        self.out_vars = []
        self.children = list()
        self.interpreter = None
        self.name = ''
        self.node = None


    def add_child(self, child):
        self.children.append(child)

    def accept(self, visitor):
        """accept: recursive function needed to implement node visitors
        Inputs:
        visitor - Visitor object
        """
        for child in self.children:
            child.accept(visitor)

    @property
    def interpreter(self):
        """Getter for the online_interpreter"""
        return self.__interpreter

    @interpreter.setter
    def interpreter(self, interpreter):
        """Setter for the online_interpreter"""
        self.__interpreter = interpreter

    @property
    def name(self):
        """Getter for the name"""
        return self.__name

    @name.setter
    def name(self, name):
        """Setter for the name"""
        self.__name = name

    @property
    def node(self):
        """Getter for the node"""
        return self.__node

    @node.setter
    def node(self, node):
        """Setter for the horizon"""
        self.__node = node

    @property
    def children(self):
        return self.__children

    @children.setter
    def children(self, children):
        self.__children = children

    @property
    def in_vars(self):
        """Getter for the in_vars"""
        return self.__in_vars

    @in_vars.setter
    def in_vars(self, in_vars):
        """Setter for the in_vars"""
        self.__in_vars = in_vars

    @property
    def out_vars(self):
        """Getter for the out_vars"""
        return self.__out_vars

    @out_vars.setter
    def out_vars(self, out_vars):
        """Setter for the out_vars"""
        self.__out_vars = out_vars

    def __repr__(self):
        '''Returns representation of the object'''
        return self.__class__.__name__

*/