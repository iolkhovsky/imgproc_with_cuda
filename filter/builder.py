from enum import Enum

from filter.cv_filter import OpencvFilter


class ProcessorType(Enum):
    NAIVE_PYTHON = 1
    OPENCV = 2
    CPP_SINGLE_THREAD = 3
    CPP_ASYNC = 4
    CPP_MULTI_THREAD = 5
    CUDA = 6


def build_filter(filter_type):
    filter_type = ProcessorType[filter_type]
    if filter_type == ProcessorType.OPENCV:
        return OpencvFilter()
    else:
        raise NotImplemented()
