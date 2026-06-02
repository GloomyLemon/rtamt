#include <abstract_online_operation.hpp>
#ifndef STL_LOG_NODE_H
#define STL_LOG_NODE_H


namespace stl_library {

class StlLogNode : public AbstractOnlineOperation {
    public:
        StlLogNode();
        double update(double sample, double base);
        void reset();
       
        bool operator==(const StlLogNode& other) const;
};

} // namespace stl_library

#endif /* STL_Log_NODE_H */

