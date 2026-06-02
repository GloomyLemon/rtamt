#ifndef STL_NEGATE_NODE_H
#define STL_NEGATE_NODE_H


namespace stl_library {

class StlNegateNode {
    public:
        StlNegateNode();
        double update(double sample);
        void reset();
       
};

} // namespace stl_library

#endif /* STL_NEGATE_NODE_H */

