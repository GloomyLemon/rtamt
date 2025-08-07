#ifndef STL_ONCE_NODE_H
#define STL_ONCE_NODE_H

#include <boost/circular_buffer.hpp>
#include <abstract_online_operation.hpp>

namespace stl_library {

class StlOnceNode : public AbstractOnlineOperation {
    private:
        double prev_out;

    public:
        StlOnceNode();
        double update(double sample, double unused = 0);
        void reset();
};

} // namespace stl_library

#endif /* STL_ONCE_NODE_H */
 