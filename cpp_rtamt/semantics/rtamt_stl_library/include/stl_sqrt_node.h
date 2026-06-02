#include <abstract_online_operation.hpp>
#ifndef STL_SQRT_NODE_H
#define STL_SQRT_NODE_H


namespace stl_library {

class StlSqrtNode : public AbstractOnlineOperation {
    public:
        StlSqrtNode();
        double update(double sample, double unused = 0);
        void reset();
       
};

} // namespace stl_library

#endif /* STL_SQRT_NODE_H */

