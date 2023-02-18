#include <iostream>
#include <vector>

#include "image.hpp"

int main(int argc, char** arvv) {
    std::cout << "Test\n";

    imgproc::Shape shape(5, 2, 3);
    imgproc::Image img(shape);

    int val = 0;
    for (auto [pixel, position]: img) {
        pixel.r() = static_cast<uint8_t>(position.x);
        pixel.g() = static_cast<uint8_t>(position.y);
        pixel.b() = static_cast<uint8_t>(position.x + position.y);
        val++;
    }

    std::cout << img;

    return 0;
}