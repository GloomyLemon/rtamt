#include <abstract_online_operation.hpp>
#ifndef STL_NOT_H
#define STL_NOT_H

namespace stl_library {

class StlNotNode : public AbstractOnlineOperation {
    private:

    public:
        StlNotNode();
        double update(double sample, double unused = 0);
        void reset();
};

} // namespace stl_library

#endif /* STL_NOT_H */

