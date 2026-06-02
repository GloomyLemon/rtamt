#ifndef STL_LOG_NODE_H
#define STL_LOG_NODE_H


namespace stl_library {

class StlLogNode {
    public:
        StlLogNode();
        double update(double sample, double base);
        void reset();
       
};

} // namespace stl_library

#endif /* STL_Log_NODE_H */

