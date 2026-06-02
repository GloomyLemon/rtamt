#include <abstract_online_operation.hpp>
#ifndef STL_EVENTUALLY_NODE_H
#define STL_EVENTUALLY_NODE_H

namespace stl_library {

class StlEventuallyNode : public AbstractOnlineOperation {
    private:
        double prev_out;

    public:
        StlEventuallyNode();
        double update(double sample, double unused = 0);
        void reset();
       
};

} // namespace stl_library

#endif /* STL_EVENTUALLY_NODE_H */

