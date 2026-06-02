#ifndef STL_TPREC_NODE_H
#define STL_TPREC_NODE_H

#include<String>
#include<vector>
#include<memory>

#include <node/binary_node.hpp>
#include <interval/interval.hpp>

namespace stl_library {


    class TimedPrecedesNode : public BinaryNode {
    private:
        Interval interval;
    public:
        TimedPrecedesNode(const PNode& lchild, const PNode& rchild, const Interval itv);

        NodeType getType() const override {
            return NodeType::TimedPrecedes;
        }

        Interval getInterval() { return interval; }
    };
}

#endif