#ifndef STL_ADDITION_NODE_H
#define STL_ADDITION_NODE_H

#include <abstract_online_operation.hpp>

namespace stl_library {

class StlAdditionNode : public AbstractOnlineOperation {
    public:
        StlAdditionNode();
        double update(double left, double right) override;
        void reset();
};

} // namespace stl_library

#endif /* STL_ADDITION_NODE_H */

