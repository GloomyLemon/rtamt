#include <abstract_online_operation.hpp>
#ifndef STL_PREVIOUS_H
#define STL_PREVIOUS_H

namespace stl_library {

class StlPreviousNode : public AbstractOnlineOperation {
    private:
        double prev_in;

    public:
        StlPreviousNode();
        double update(double sample, double unused = 0);
        void reset();
};

} // namespace stl_library

#endif /* STL_PREVIOUS_H */

