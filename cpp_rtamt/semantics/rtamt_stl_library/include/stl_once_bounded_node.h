#ifndef STL_ONCE_BOUNDED_NODE_H
#define STL_ONCE_BOUNDED_NODE_H

#include <abstract_online_operation.hpp>

namespace stl_library {

class StlOnceBoundedNode : public AbstractOnlineOperation {
    private:
        struct Impl;
        Impl* impl;

    public:
        StlOnceBoundedNode(int begin, int end);
        ~StlOnceBoundedNode();

        double update(double sample, double unused = 0);
        void reset();
};

} // namespace stl_library

#endif /* STL_ONCE_BOUNDED_NODE_H */

