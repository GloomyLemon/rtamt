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


void AbstractNode::setOperation(void* operation) {
    op = operation;
}

void* AbstractNode::getOperation() {
    return op;
}
