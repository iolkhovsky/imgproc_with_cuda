#include "image.hpp"

#include <iostream>

namespace imgproc {

Shape::Shape(const int& width, const int& height, const int& channels)
    : width(width)
    , height(height)
    , channels(channels) {}

int Shape::Size() const {
    return width * height * channels;
}

bool Shape::operator==(const Shape& other) const {
    return width == other.width
        && height == other.height
        && channels == other.channels;
}

bool Coord::operator==(const Coord& other) const {
    return x == other.x && y == other.y;
}

std::ostream& operator<<(std::ostream& os, const Image<uint8_t>& img) {
    std::cout << "Image:\n";
    auto shape = img.shape();
    for (int y = 0; y < shape.height; y++) {
        for (int x = 0; x < shape.width; x++) {
            const auto pixel = img(x, y);
            std::cout << "{" << pixel.get_r() << ", " << pixel.get_g() << ", " << pixel.get_b() << "} ";
        }
        std::cout << "\n";
    }
    return os;
}

}  // imgproc
