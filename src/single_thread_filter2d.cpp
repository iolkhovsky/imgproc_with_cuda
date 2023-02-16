#include <algorithm>

#include "src/single_thread_filter2d.hpp"

namespace imgproc {

void SingleThreadFilter2d::process(
    const uint8_t* img,
    const Size& img_size,
    const uint8_t* filter,
    const Size& filter_size,
    uint8_t* output
) const {
    int y_kernel_center = filter_size.height / 2;
    int x_kernel_center = filter_size.width / 2;
    for (int y = 0; y < img_size.height; y++)
        for (int x = 0; x < img_size.height; x++) {
            float result = 0.;
            for (int ky = 0; ky < filter_size.height; ky++)
                for (int kx = 0; kx < filter_size.width; kx++) {
                    int px = x - x_kernel_center + kx;
                    int py = y - y_kernel_center + ky;
                }
            output[y * img_size.width + x] = static_cast<uint8_t>(
                std::max<float>(std::min<float>(result, 255.), 0.)
            );
        }
}

SingleThreadFilter2d* SingleThreadFilter2d_create() {
    return new SingleThreadFilter2d();
}

void SingleThreadFilter2d_process(
    const SingleThreadFilter2d* obj,
    const uint8_t* img,
    const Size& img_size,
    const uint8_t* filter,
    const Size& filter_size,
    uint8_t* output
) {
    obj->process(img, img_size, filter, filter_size, output);
}

}
