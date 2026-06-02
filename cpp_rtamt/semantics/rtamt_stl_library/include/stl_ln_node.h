#include <abstract_online_operation.hpp>
#ifndef STL_LN_NODE_H
#define STL_LN_NODE_H


namespace stl_library {

class StlLnNode : public AbstractOnlineOperation {
    public:
        StlLnNode();
        double update(double sample, double unused = 0);
        void reset();
       
};

} // namespace stl_library

#endif /* STL_Ln_NODE_H */

