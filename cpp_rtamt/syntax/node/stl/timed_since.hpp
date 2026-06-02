#ifndef STL_TSIN_NODE_H
#define STL_TSIN_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>
#include <interval/interval.hpp>

namespace stl_library {


    class TimedSinceNode : public BinaryNode {
    private:
        Interval interval;
    public:
        TimedSinceNode(const PNode& lchild, const PNode& rchild, const Interval itv);

        NodeType getType() const override {
            return NodeType::TimedSince;
        }

        Interval getInterval() { return interval; }
    };
}

#endif
