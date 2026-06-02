#include <node/binary_node.hpp>

using namespace stl_library;

BinaryNode::BinaryNode() {}

BinaryNode::BinaryNode(const PNode& l, const PNode& r) {
    add_child(l);
    add_child(r);
}




