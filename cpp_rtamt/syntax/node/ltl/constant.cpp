#include <node/ltl/constant.hpp>

#include <string>

using namespace stl_library;

ConstantNode::ConstantNode(const double val) {
    value = val;
    name = std::to_string(val);
}
