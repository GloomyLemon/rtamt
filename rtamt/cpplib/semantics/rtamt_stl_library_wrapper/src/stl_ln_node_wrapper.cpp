#include <boost/python.hpp>
#include <boost/python/def.hpp>
#include <boost/python/module.hpp>
#include <boost/python/wrapper.hpp>

#include <rtamt_stl_library/stl_ln_node.h>

using namespace boost::python;
using namespace stl_library;

BOOST_PYTHON_MODULE(stl_ln_node)
{
    class_<StlLnNode>("LnOperation")
        .def("update", static_cast<double (StlLnNode::*)(double)>(&StlLnNode::update))
        .def("reset", &StlLnNode::reset)
    ;
}

