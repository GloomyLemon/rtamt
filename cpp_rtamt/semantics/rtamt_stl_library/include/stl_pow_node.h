#include <abstract_online_operation.hpp>
#ifndef STL_POW_NODE_H
#define STL_POW_NODE_H


namespace stl_library {

class StlPowNode : public AbstractOnlineOperation {
    public:
        StlPowNode();
        double update(double base, double exponent);
        void reset();
       
};

} // namespace stl_library

#endif /* STL_Pow_NODE_H */

