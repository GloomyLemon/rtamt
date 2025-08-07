#include <boost/python.hpp>
#include <boost/python/def.hpp>
#include <boost/python/module.hpp>
#include <boost/python/wrapper.hpp>

#include <rtamt_stl_library/stl_negate_node.h>

using namespace boost::python;
using namespace stl_library;

BOOST_PYTHON_MODULE(stl_negate_node)
{
    class_<StlNegateNode>("NegateOperation")
        .def("update", static_cast<double (StlNegateNode::*)(double)>(&StlNegateNode::update))
        .def("reset", &StlNegateNode::reset)
    ;
}

