import time


class Profiler:
    def __init__(self, hint):
        assert isinstance(hint, str)
        self._hint = hint
        self._start = None

    def __enter__(self):
        self._start = time.time()

    def __exit__(self, type, value, traceback):
        duration = time.time() - self._start
        duration_ms = "{:.3f}".format(duration * 1000.)
        fps =  "{:.2f}".format(1. / (duration + 1e-5))
        print(f"{self._hint} duration (msec):\t{duration_ms}\tFPS={fps}")
