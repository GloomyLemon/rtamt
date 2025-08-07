#pragma once

#include <vector>
#include <memory>

namespace stl_library {

    class AbstractOnlineOperation;
    typedef std::shared_ptr<AbstractOnlineOperation> POperation;
    
    class AbstractOnlineOperation {
    private:

    public:
        AbstractOnlineOperation() {}
        virtual double update(double lparam = 0, double rparam = 0) = 0;
        virtual void reset() = 0;
    };


}

/*
* # -*- coding: utf-8 -*-
from abc import ABCMeta, abstractmethod


class AbstractOnlineOperation:
    """
    Abstract Operation: template for online operation
    """
    __metaclass__ = ABCMeta

    NOT_IMPLEMENTED = "You should implement this."

    @abstractmethod
    def __init__(self, *args, **kargs):
        raise NotImplementedError(self.NOT_IMPLEMENTED)

    @abstractmethod
    def update(self, node, *args, **kargs):
        raise NotImplementedError(self.NOT_IMPLEMENTED)

    @abstractmethod
    def reset(self):
        raise NotImplementedError(self.NOT_IMPLEMENTED)

*/
