#include <boost/config.hpp>
#include <exception>
#include <cstdlib>

namespace boost {

void throw_exception(std::exception const& e) {
    (void)e;
    std::abort();  // No exceptions → abort instead
}

}