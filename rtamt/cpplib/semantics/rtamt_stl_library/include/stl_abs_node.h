#ifndef STL_ABS_NODE_H
#define STL_ABS_NODE_H

#include <abstract_online_operation.hpp>

namespace stl_library {

class StlAbsNode : public AbstractOnlineOperation {
    public:
        StlAbsNode();
        double update(double sample, double rsample = 0) override;
        void reset();
       
};

} // namespace stl_library

#endif /* STL_ABS_NODE_H */

