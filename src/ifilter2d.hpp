#pragma once

#include "src/utils.hpp"

namespace imgproc {

class IFilter2d {
    public:
        virtual void process(
            const uint8_t* img,
            const Size& img_size,
            const uint8_t* filter,
            const Size& filter_size,
            uint8_t* output
        ) const = 0;
        virtual ~IFilter2d() = default;
};

}
