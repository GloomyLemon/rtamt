from rtamt.semantics.abstract_online_operation import AbstractOnlineOperation
import math

class LnOperation(AbstractOnlineOperation):
    def __init__(self):
        pass

    def reset(self):
        pass

    def update(self, sample):
        sample_result = math.log(sample)
        return sample_result