#ifndef STL_CONSTANT_H
#define STL_CONSTANT_H

#include <abstract_online_operation.hpp>

namespace stl_library {

class StlConstantNode : public AbstractOnlineOperation {
    private:
        double val;

    public:
        StlConstantNode();
        StlConstantNode(double val);

        double update(double lsample = 0, double rsample = 0);
        void reset();
        //double getValue() const { return val; }
};

} // namespace stl_library

#endif /* STL_NOT_H */

