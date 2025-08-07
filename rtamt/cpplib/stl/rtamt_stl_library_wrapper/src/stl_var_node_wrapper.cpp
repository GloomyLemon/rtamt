#include <boost/python.hpp>
#include <boost/python/def.hpp>
#include <boost/python/module.hpp>
#include <boost/python/wrapper.hpp>

#include <rtamt_stl_library/stl_var_node.h>

using namespace boost::python;
using namespace stl_library;

BOOST_PYTHON_MODULE(stl_var_node)
{
    class_<StlVarNode>("VariableOperation")
        .def("update", static_cast<double (StlVarNode::*)(double)>(&StlVarNode::update))
        .def("reset", &StlVarNode::reset)
    ;
}

