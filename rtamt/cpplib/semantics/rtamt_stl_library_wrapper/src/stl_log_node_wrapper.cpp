#include <boost/python.hpp>
#include <boost/python/def.hpp>
#include <boost/python/module.hpp>
#include <boost/python/wrapper.hpp>

#include <rtamt_stl_library/stl_log_node.h>

using namespace boost::python;
using namespace stl_library;

BOOST_PYTHON_MODULE(stl_log_node)
{
    class_<StlLogNode>("LogOperation")
        .def("update", static_cast<double (StlLogNode::*)(double, double)>(&StlLogNode::update))
        .def("reset", &StlLogNode::reset)
    ;
}

