#ifndef STL_HISTORICALLY_BOUNDED_NODE_H
#define STL_HISTORICALLY_BOUNDED_NODE_H

#include <abstract_online_operation.hpp>

namespace stl_library {

class StlHistoricallyBoundedNode: public AbstractOnlineOperation {
    private:
        //int begin;
        //int end;
        //boost::circular_buffer<double> buffer;
        struct Impl;
        Impl* impl;

    public:
        StlHistoricallyBoundedNode(int begin, int end);
        ~StlHistoricallyBoundedNode();

        double update(double sample, double rsample);
        void reset();
       
};

} // namespace stl_library

#endif /* STL_HISTORICALLY_BOUNDED_NODE_H */

