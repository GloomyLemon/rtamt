#include <abstract_online_operation.hpp>
#ifndef STL_ALWAYS_NODE_H
#define STL_ALWAYS_NODE_H

namespace stl_library {

class StlAlwaysNode : public AbstractOnlineOperation {
    private:
        double prev_out;

    public:
        StlAlwaysNode();
        double update(double sample, double unused = 0);
        void reset();
       
};

} // namespace stl_library

#endif /* STL_ALWAYS_NODE_H */

