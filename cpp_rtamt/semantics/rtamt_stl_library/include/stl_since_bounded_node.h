#ifndef STL_SINCE_BOUNDED_NODE_H
#define STL_SINCE_BOUNDED_NODE_H

#include <abstract_online_operation.hpp>

namespace stl_library {

class StlSinceBoundedNode : public AbstractOnlineOperation {
    private:
        struct Impl;
        Impl* impl;

    public:
        StlSinceBoundedNode(int begin, int end);
        ~StlSinceBoundedNode();

        double update(double left, double right);
        void reset();
       
};

} // namespace stl_library

#endif /* STL_SINCE_BOUNDED_NODE_H */

