#include <rtamt_stl_library/include/stl_pow_node.h>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;
using namespace stl_library;

// Initialize previous and current value
StlPowNode::StlPowNode() {
}

void StlPowNode::reset() {
}

double StlPowNode::update(double base, double exponent) {
    double out;
    

	constexpr double eps = 1e-9;

	if (base <= 0.0 && std::abs(std::floor(exponent) - exponent) > eps)  {
        out = -std::numeric_limits<double>::infinity();
    }
    else {
        out = pow(base, exponent);
    }

    out = sanitize(out);

    return out;
}

