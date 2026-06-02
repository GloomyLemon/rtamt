#ifndef STL_TONCE_NODE_H
#define STL_TONCE_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>
#include <interval/interval.hpp>

namespace stl_library {


    class TimedOnceNode : public UnaryNode {
    private:
        Interval interval;
    public:
        TimedOnceNode(const PNode& child, const Interval itv);

        NodeType getType() const override {
            return NodeType::TimedOnce;
        }

        Interval getInterval() { return interval; }
    };
}

#endif