#include <node/unary_node.hpp>

using namespace stl_library;

UnaryNode::UnaryNode(const PNode& c) {
    add_child(c);
}


