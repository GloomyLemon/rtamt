#include <abstract_online_operation.hpp>
#ifndef STL_MULTIPLICATION_NODE_H
#define STL_MUTIPLICATION_NODE_H

namespace stl_library {

class StlMultiplicationNode : public AbstractOnlineOperation {
    public:
        StlMultiplicationNode();
        double update(double left, double right);
        void reset();
};

} // namespace stl_library

#endif /* STL_MULTIPLICATION_NODE_H */

