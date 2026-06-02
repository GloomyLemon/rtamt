#ifndef STL_HISTORICALLY_NODE_H
#define STL_HISTORICALLY_NODE_H

#include <boost/circular_buffer.hpp>
#include <abstract_online_operation.hpp>

namespace stl_library {

class StlHistoricallyNode : public AbstractOnlineOperation {
    private:
        double prev_out;

    public:
        StlHistoricallyNode();
        double update(double sample, double unused = 0);
        void reset();
};

} // namespace stl_library

#endif /* STL_HISTORICALLY_NODE_H */

