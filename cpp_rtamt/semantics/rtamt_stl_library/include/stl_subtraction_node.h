#include <abstract_online_operation.hpp>
#ifndef STL_SUBTRACTION_NODE_H
#define STL_SUBTRACTION_NODE_H

namespace stl_library {

class StlSubtractionNode : public AbstractOnlineOperation {
    public:
        StlSubtractionNode();
        double update(double left, double right);
        void reset();
        bool operator==(const StlSubtractionNode& other) const;
};

} // namespace stl_library

#endif /* STL_SUBTRACTION_NODE_H */

