#ifndef STL_TUNT_NODE_H
#define STL_TUNT_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>
#include <interval/interval.hpp>

namespace stl_library {


    class TimedUntilNode : public BinaryNode {
    private:
        Interval interval;
    public:
        TimedUntilNode(const PNode& lchild, const PNode& rchild, const Interval itv);

        NodeType getType() const override {
            return NodeType::TimedUntil;
        }

        Interval getInterval() { return interval; }
    };
}

#endif