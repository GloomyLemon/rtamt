#pragma once

#include <map>
#include <vector>
#include <string>
#include <utility>

namespace stl_library {

    typedef std::map<std::string, double> DataSet;

    class AbstractTimeInterpreter {
    private:

    public:
        AbstractTimeInterpreter() {}
        virtual bool dataset_check(DataSet& p_dataset) = 0;
        virtual void set_variable_to_ast_from_dataset(const DataSet& p_dataset) = 0;
    };

}


/*
from abc import ABCMeta, abstractmethod

from rtamt.exception.exception import RTAMTException


class TimeInterpreter(object):
    __metaclass__ = ABCMeta

    def __init__(self):
        pass

    @abstractmethod
    def dataset_check(self, data):
        pass

    @abstractmethod
    def set_variable_to_ast_from_dataset(self, *args, **kargs):
        pass
*/
