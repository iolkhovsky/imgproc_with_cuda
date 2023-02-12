import argparse
import cv2
import numpy as np

from utils.profiler import Profiler
from filter import build_filter


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('--source', default=0, help='Videostream source')
    parser.add_argument('--filter', default='OPENCV', help='Filter type')
    return parser.parse_args()


def run(args):
    video_source = str(args.source)
    if video_source.isdigit():
        video_source = int(video_source)
    cap = cv2.VideoCapture(video_source)

    profiler = Profiler("Processing")

    kernel_size = 7
    kernel = np.ones(
        shape=[kernel_size, kernel_size],
        dtype=np.float32,
    ) * (1. / (kernel_size ** 2))

    processor = build_filter(args.filter)

    while True:
        ret, frame = cap.read()
        if not ret:
            break
        
        with profiler:
            processed_img = processor(frame, kernel)

        cv2.imshow('Processed image', processed_img)

        if cv2.waitKey(10) & 0xFF == ord('q'):
            break

    cap.release()
    cv2.destroyAllWindows()


if __name__ == "__main__":
    run(parse_args())
