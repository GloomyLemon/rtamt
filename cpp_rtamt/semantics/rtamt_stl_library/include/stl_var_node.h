#ifndef STL_VAR_NODE_H
#define STL_VAR_NODE_H

#include <abstract_online_operation.hpp>

namespace stl_library {

class StlVarNode : public AbstractOnlineOperation {
    public:
        StlVarNode();
        double update(double sample, double rsample = 0);
        void reset();
       
};

} // namespace stl_library

#endif /* STL_VAR_NODE_H */

