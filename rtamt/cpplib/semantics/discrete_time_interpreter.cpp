#include <discrete_time_interpreter.hpp>

#include <interval/interval.hpp>

#include <cmath>
#include <iostream>

using namespace stl_library;

AbstractDiscreteTimeInterpreter::AbstractDiscreteTimeInterpreter() {
    set_sampling_period(1.0, "s", 0.1);
}

double AbstractDiscreteTimeInterpreter::get_sampling_frequency() {
    return 1 / get_sampling_period();
}

double AbstractDiscreteTimeInterpreter::get_sampling_period() {
    return sampling_period * units[sampling_period_unit];
}

int AbstractDiscreteTimeInterpreter::get_violation_count() {
    return sampling_violation_counter;
}

void AbstractDiscreteTimeInterpreter::set_sampling_period(double p_period, std::string p_unit, double p_tolerance) {
    sampling_period = p_period;
    sampling_period_unit = p_unit;
    sampling_tolerance = p_tolerance;
}

bool AbstractDiscreteTimeInterpreter::dataset_check(DataSet& p_dataset) {
    return true;
}

void AbstractDiscreteTimeInterpreter::update_sampling_violation_counter(double duration) {
    double tolerance = sampling_period * sampling_tolerance;
    if (duration < sampling_period - tolerance || duration > sampling_period + tolerance) {
        sampling_violation_counter += 1;
    }
}

std::pair<int, int> AbstractDiscreteTimeInterpreter::time_unit_transformer(Interval& itv) {
    double b = itv.getBegin();
    double e = itv.getEnd();
    std::string b_unit = itv.getBeginUnit();
    std::string e_unit = itv.getEndUnit();

    //if (len(node.begin_unit) == 0) {
    //    if (len(node.end_unit) > 0) {
    //        b_unit = node.end_unit;
    //    } else {
    //        b_unit = self.ast.unit;
    //        e_unit = self.ast.unit;
    //    }
    //}

    b = b * units[b_unit];
    e = e * units[e_unit];

    double sp = sampling_period * units[sampling_period_unit];
    b = b / sp;
    e = e / sp;

    if (std::fmod(b, 1) > 0) {
        std::cout << "The operator bound must be a multiple of the sampling period";
    }
    if (std::fmod(e, 1) > 0) {
        std::cout << "The operator bound must be a multiple of the sampling period";
    }

    int bint = int(b);
    int eint = int(e);


    return std::pair<int, int>(bint, eint);
}

/*
* 
from fractions import Fraction
from rtamt.semantics.time_interpreter import TimeInterpreter
from rtamt.exception.exception import RTAMTException

class DiscreteTimeInterpreter(TimeInterpreter):

    def __init__(self):
        super(DiscreteTimeInterpreter, self).__init__()

        self.DEFAULT_TOLERANCE = float(0.1)

        self.S_UNIT = int(1000000000)
        self.MS_UNIT = int(1000000)
        self.US_UNIT = int(1000)
        self.NS_UNIT = int(1)

        self.U = {
            's': self.S_UNIT,
            'ms': self.MS_UNIT,
            'us': self.US_UNIT,
            'ns': self.NS_UNIT
        }

        # Default sampling period - 1s
        self.sampling_period = int(1)
        self.sampling_period_unit = 's'

        # Default sampling tolerance
        self.sampling_tolerance = float(0.1)

        self.update_counter = int(0)
        self.previous_time = float(0.0)
        self.sampling_violation_counter = int(0)

        self.normalize = float(1.0)

        return

    @property
    def sampling_period(self):
        return self.__sampling_period

    @sampling_period.setter
    def sampling_period(self, sampling_period):
        self.__sampling_period = sampling_period

    @property
    def sampling_tolerance(self):
        return self.__sampling_tolerance

    @sampling_tolerance.setter
    def sampling_tolerance(self, sampling_tolerance):
        self.__sampling_tolerance = sampling_tolerance

    @property
    def sampling_period_unit(self):
        return self.__sampling_period_unit

    @sampling_period_unit.setter
    def sampling_period_unit(self, sampling_period_unit):
        self.__sampling_period_unit = sampling_period_unit

    @property
    def sampling_violation_counter(self):
        return self.__sampling_violation_counter

    @sampling_violation_counter.setter
    def sampling_violation_counter(self, sampling_violation_counter):
        self.__sampling_violation_counter = sampling_violation_counter

    def set_sampling_period(self, sampling_period=int(1), unit='s', tolerance=float(0.1)):
        self.sampling_period = sampling_period
        self.sampling_period_unit = unit

        if tolerance < 0.0 or tolerance > 1.0:
            raise Exception('Tolerance must be in [0,1]')

        self.sampling_tolerance = tolerance

    def get_sampling_period(self):
        return self.sampling_period * self.U[self.sampling_period_unit]

    def get_sampling_frequency(self):
        return 1e9 * 1/self.get_sampling_period()


    #input format
    #a = [[0, 1.3], [0.7, 3], [1.3, 0.1], [2.1, -2.2]]
    #b = [[0, 2.5], [0.7, 4], [1.3, -1.2], [2.1, 1.7]]
    #dataset = [['a', a], ['b', b]]
    def dataset_check(self, dataset):
        #TODO check that data fromat more.
        if not dataset['time']:
            #TODO consider appropriate exception
            raise RTAMTException('evaluate: The input does not contain the time field')
        return

    def update_sampling_violation_counter(self, duration):
        tolerance = self.sampling_period * self.sampling_tolerance
        if duration < self.sampling_period - tolerance or duration > self.sampling_period + tolerance:
            self.sampling_violation_counter = self.sampling_violation_counter + 1

    def time_unit_transformer(self, node):
        b = node.begin
        e = node.end
        b_unit = node.begin_unit
        e_unit = node.end_unit
        if len(node.begin_unit) == 0:
            if len(node.end_unit) > 0:
                b_unit = node.end_unit
            else:
                b_unit = self.ast.unit
                e_unit = self.ast.unit

        b = b * self.ast.U[b_unit]
        e = e * self.ast.U[e_unit]

        sp = Fraction(self.sampling_period * self.ast.U[self.sampling_period_unit])
        b = b / sp
        e = e / sp

        if b.numerator % b.denominator > 0:
            raise RTAMTException('The operator bound must be a multiple of the sampling period')

        if e.numerator % e.denominator > 0:
            raise RTAMTException('The operator bound must be a multiple of the sampling period')

        b = int(b)
        e = int(e)

        return b, e

*/
