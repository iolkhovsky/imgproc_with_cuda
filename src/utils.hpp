#pragma once

#include <stddef.h>
#include <cstdint>

namespace imgproc {

template<class T>
struct ImageShape {
    T width;
    T height;
    T channels;
};

template<class T, int Channels>
class Pixel {
public:
    Pixel(const T* ptr)
    : data_(ptr) {}

    T& operator[](const int& idx) {
        return data[idx];
    }
    T& R() {
        return data[std::min(Channels, 0)];
    }
    T& G() {
        return data[std::min(Channels, 1)];
    }
    T& B() {
        return data[std::min(Channels, 2)];
    }
private:
    T* data_;
};

using GrayPixel = Pixel<uint8_t, 1>;
using RgbPixel = Pixel<uint8_t, 3>;

template<class DType>
class ImageIterator {
public:
    ImageIterator(const DType* ptr, const int stride = 3)
    : ptr_(ptr)
    , stride_(stride) {}

    Pixel operator*() const{
        return {ptr_[0], ptr_[1], ptr_[2]};
    }

    const Pixel* operator->() const {
        return static_cast<Pixel*>(ptr_);
    }

    bool operator==(const PixelIterator& other) const {
        return ptr_ == other.ptr_;
    }

    bool operator!=(const PixelIterator& other) const {
        return !(this->operator==(other));
    }

    PixelIterator& operator++() {
        ptr_ += stride_;
        return *this;
    }

private:
    DType* ptr_;
    int stride_;
};

template<class DType>
class ImageContainer {
public:
    Image(const DType* buffer, const Size<int>& size);
};

}
