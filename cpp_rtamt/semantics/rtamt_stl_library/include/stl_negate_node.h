#include <abstract_online_operation.hpp>
#ifndef STL_NEGATE_NODE_H
#define STL_NEGATE_NODE_H


namespace stl_library {

class StlNegateNode : public AbstractOnlineOperation {
    public:
        StlNegateNode();
        double update(double sample, double unused = 0);
        void reset();
};

} // namespace stl_library

#endif /* STL_NEGATE_NODE_H */

