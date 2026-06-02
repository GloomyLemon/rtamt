#ifndef STL_SINCE_NODE_H
#define STL_SINCE_NODE_H

#include <boost/circular_buffer.hpp>
#include <abstract_online_operation.hpp>

namespace stl_library {

class StlSinceNode : public AbstractOnlineOperation {
    private:
        double prev_out;

    public:
        StlSinceNode();
        double update(double left, double right);
        void reset();
};

} // namespace stl_library

#endif /* STL_SINCE_NODE_H */

