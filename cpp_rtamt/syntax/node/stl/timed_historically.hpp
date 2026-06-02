#ifndef STL_THIS_NODE_H
#define STL_THIS_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>
#include <interval/interval.hpp>

namespace stl_library {


    class TimedHistoricallyNode : public UnaryNode {
    private:
        Interval interval;
    public:
        TimedHistoricallyNode(const PNode& child, const Interval itv);

        NodeType getType() const override {
            return NodeType::TimedHistorically;
        }

        Interval getInterval() { return interval; }
    };
}

#endif
