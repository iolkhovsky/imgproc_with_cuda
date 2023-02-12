from abc import ABC, abstractmethod
import numpy as np


class IFilter(ABC):
    @abstractmethod
    def process(self, image, kernel):
        pass

    def __call__(self, image, kernel):
        assert isinstance(image, np.ndarray)
        assert image.dtype == np.uint8
        assert len(image.shape) == 3 and image.shape[2] == 3
        assert isinstance(kernel, np.ndarray)
        assert len(kernel.shape) == 2
        return self.process(image, kernel)
