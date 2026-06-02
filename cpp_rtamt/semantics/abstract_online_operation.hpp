#pragma once

#include <vector>
#include <memory>
#include <cmath>

namespace stl_library {

    class AbstractOnlineOperation;
    typedef std::shared_ptr<AbstractOnlineOperation> POperation;
    
    class AbstractOnlineOperation {
    private:

    protected:
        static double sanitize(double x) {
            if (std::isnan(x)) {
                return -std::numeric_limits<double>::infinity();
            }
            return x;
        }

    public:
        virtual ~AbstractOnlineOperation() = default;
        AbstractOnlineOperation() {}
        virtual double update(double lparam = 0, double rparam = 0) = 0;
        virtual void reset() = 0;
    };


}