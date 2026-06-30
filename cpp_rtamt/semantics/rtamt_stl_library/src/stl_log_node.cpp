#include <rtamt_stl_library/include/stl_log_node.h>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;
using namespace stl_library;

// Initialize previous and current value
StlLogNode::StlLogNode() {
}

void StlLogNode::reset() {
}

double StlLogNode::update(double sample, double base) {
    double out;


	const double eps = 1e-9;

	if (sample <= 0.0 || base <= 0.0 || std::fabs(base - 1.0) < eps) {

        out = -std::numeric_limits<double>::infinity();
    }
    else {
        out = std::log(sample) / std::log(base);
    }

    return sanitize(out);
}


bool stl_library::StlLogNode::operator==(const StlLogNode& other) const
{
    return false;
}
