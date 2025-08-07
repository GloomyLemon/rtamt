#ifndef STL_ONCE_BOUNDED_NODE_H
#define STL_ONCE_BOUNDED_NODE_H

#include <boost/circular_buffer.hpp>
#include <abstract_online_operation.hpp>

namespace stl_library {

class StlOnceBoundedNode : public AbstractOnlineOperation {
    private:
        int begin;
        int end;
        boost::circular_buffer<double> buffer;

    public:
        StlOnceBoundedNode(int begin, int end);
        double update(double sample, double unused = 0);
        void reset();
};

} // namespace stl_library

#endif /* STL_ONCE_BOUNDED_NODE_H */

