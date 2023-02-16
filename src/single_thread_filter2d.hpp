#pragma once

#include "src/ifilter2d.hpp"

namespace imgproc {

class SingleThreadFilter2d : public IFilter2d {
    public:
        void process(
            const uint8_t* img,
            const Size& img_size,
            const uint8_t* filter,
            const Size& filter_size,
            uint8_t* output
        ) const override;
};

extern "C" {
    SingleThreadFilter2d* SingleThreadFilter2d_create();
    void SingleThreadFilter2d_process(
        const SingleThreadFilter2d* obj,
        const uint8_t* img,
        const Size& img_size,
        const uint8_t* filter,
        const Size& filter_size,
        uint8_t* output
    );
}

}