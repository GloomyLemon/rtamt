#ifndef STL_TALW_NODE_H
#define STL_TALW_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>
#include <interval/interval.hpp>

namespace stl_library {


    class TimedAlwaysNode : public UnaryNode {
    private:
        Interval interval;
    public:
        TimedAlwaysNode(const PNode& child, const Interval itv);

        NodeType getType() const override {
            return NodeType::TimedAlways;
        }

        Interval getInterval() { return interval; }
    };
}

#endif