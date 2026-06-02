#include <abstract_online_operation.hpp>
#ifndef STL_RISE_H
#define STL_RISE_H

namespace stl_library {

class StlRiseNode : public AbstractOnlineOperation {
    private:
        double prev_in;

    public:
        StlRiseNode();
        double update(double sample, double unused = 0);
        void reset();
};

} // namespace stl_library

#endif /* STL_RISE_H */

