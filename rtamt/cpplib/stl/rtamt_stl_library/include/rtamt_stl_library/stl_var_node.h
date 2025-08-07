#ifndef STL_VAR_NODE_H
#define STL_VAR_NODE_H


namespace stl_library {

class StlVarNode {
    public:
        StlVarNode();
        double update(double sample);
        void reset();
       
};

} // namespace stl_library

#endif /* STL_VAR_NODE_H */

