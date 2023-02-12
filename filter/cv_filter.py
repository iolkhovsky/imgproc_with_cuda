import cv2

from filter.interface import IFilter


class OpencvFilter(IFilter):
    def __init__(self):
        super().__init__()

    def process(self, image, kernel):
        return cv2.filter2D(image, cv2.CV_8U, kernel)
