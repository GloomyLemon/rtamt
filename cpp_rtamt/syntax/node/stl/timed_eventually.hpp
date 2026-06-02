#ifndef STL_TEVT_NODE_H
#define STL_TEVT_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/unary_node.hpp>
#include <interval/interval.hpp>

namespace stl_library {


    class TimedEventuallyNode : public UnaryNode {
    private:
        Interval interval;
    public:
        TimedEventuallyNode(const PNode& child, const Interval itv);

        NodeType getType() const override {
            return NodeType::TimedEventually;
        }

        Interval getInterval() { return interval; }
    };
}

#endif