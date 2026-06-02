#ifndef STL_PREDICATE_NODE_H
#define STL_PREDICATE_NODE_H

//#include <rtamt_stl_library/include/stl_comp_op.h>

#include <abstract_online_operation.hpp>
#include <node/ltl/predicate.hpp>


namespace stl_library {

class StlPredicateNode: public AbstractOnlineOperation {
    private:
        OperatorType op;

    public:
        StlPredicateNode() = delete;
        StlPredicateNode(OperatorType op);
        double update(double left, double right);
        void reset();
};

} // namespace stl_library

#endif /* STL_PREDICATE_NODE_H */

