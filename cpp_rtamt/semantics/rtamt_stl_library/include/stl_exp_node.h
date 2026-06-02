#include <abstract_online_operation.hpp>
#ifndef STL_EXP_NODE_H
#define STL_EXP_NODE_H


namespace stl_library {

class StlExpNode : public AbstractOnlineOperation {
    public:
        StlExpNode();
        double update(double sample, double unused = 0);
        void reset();
};

} // namespace stl_library

#endif /* STL_EXP_NODE_H */

