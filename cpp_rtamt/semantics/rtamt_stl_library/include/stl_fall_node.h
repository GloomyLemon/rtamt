#include <abstract_online_operation.hpp>
#ifndef STL_FALL_H
#define STL_FALL_H

namespace stl_library {

class StlFallNode : public AbstractOnlineOperation {
    private:
        double prev_in;

    public:
        StlFallNode();
        double update(double sample, double unused = 0);
        void reset();
       
};

} // namespace stl_library

#endif /* STL_RISE_H */

