#ifndef STL_PRECEDES_BOUNDED_NODE_H
#define STL_PRECEDES_BOUNDED_NODE_H

#include <abstract_online_operation.hpp>

namespace stl_library {

class StlPrecedesBoundedNode : public AbstractOnlineOperation {
    private:
        struct Impl;
        Impl* impl;
        
    public:
        StlPrecedesBoundedNode(int begin, int end);
        ~StlPrecedesBoundedNode();

        double update(double left, double right);
        void reset();
};

} // namespace stl_library

#endif /* STL_PRECEDES_BOUNDED_NODE_H */

