#include <abstract_online_operation.hpp>
#ifndef STL_DIVISION_NODE_H
#define STL_DIVISION_NODE_H

namespace stl_library {

class StlDivisionNode : public AbstractOnlineOperation {
    private:

    public:
        StlDivisionNode();
        double update(double left, double right);
        void reset();
        bool operator==(const StlDivisionNode& other) const;
};

} // namespace stl_library

#endif /* STL_DIVISION_NODE_H */

