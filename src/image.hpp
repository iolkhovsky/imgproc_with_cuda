#pragma once

#include <memory>
#include <stddef.h>
#include <cstdint>

namespace imgproc {

struct Shape {
    Shape(const int& width, const int& height, const int& channels = 1);
    int Size() const;
    bool operator==(const Shape& other) const;

    int width;
    int height;
    int channels;
};

struct Coord {
    bool operator==(const Coord& other) const;
    int x;
    int y;
};

template<class T = uint8_t>
class PixelView {
    public:
        explicit PixelView(T* const ptr)
        : ptr_(ptr) {}

        const T& get_r() const { return ptr_[0]; }
        T& r() const { return ptr_[0]; }
        const T& get_g() const { return ptr_[1]; }
        T& g() const { return ptr_[1]; }
        const T& get_b() const { return ptr_[2]; }
        T& b() const { return ptr_[2]; }

    private:
        T* const ptr_;
};

template<class T>
class ImageIterator {
    public:
        ImageIterator(T* const ptr, const Coord& position, const Shape& shape)
        : ptr_(ptr)
        , coord_(position)
        , shape_(shape) {}

        ImageIterator& operator++() {
            coord_.x++;
            if (coord_.x == shape_.width) {
                coord_.y++;
                coord_.x = 0;
            }
            return *this;
        }

        bool operator==(const ImageIterator& other) const {
            return (ptr_ == other.ptr_)
                && (coord_ == other.coord_)
                && (shape_ == other.shape_);
        }

        bool operator!=(const ImageIterator& other) const {
            return !operator==(other);
        }

        std::pair<PixelView<T>, Coord> operator*() const {
            return {
                PixelView<T>(ptr_ + (coord_.y * shape_.width + coord_.x) * shape_.channels),
                coord_
            };
        }

    private:
        T* const ptr_;
        const Shape shape_;
        Coord coord_;
};

template<class T = uint8_t>
class Image {
    public:
        Image(const T* ptr, const Shape& shape)
        : ptr_(ptr)
        , shape_(shape) {}

        Image(const Shape& shape)
        : owner_(std::make_unique<T>(shape.Size() * sizeof(T)))
        , ptr_(owner_.get())
        , shape_(shape) {}

        PixelView<T> operator()(int x, int y) const{
            return PixelView<T>(ptr_ + (y * shape_.width + x) * shape_.channels);
        }

        ImageIterator<T> begin() {
            return ImageIterator<T>(ptr_, {0, 0}, shape_);
        }

        ImageIterator<T> end() {
            return ImageIterator<T>(ptr_, {0, shape_.height}, shape_);
        }

        const Shape& shape() const {
            return shape_;
        }
        
    private:
        std::unique_ptr<T> owner_;
        T* const ptr_;
        const Shape shape_;
};

std::ostream& operator<<(std::ostream& os, const Image<uint8_t>& img);

}  // imgproc
