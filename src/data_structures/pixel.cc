#include <cmath>

#include "pixel.h"

Pixel::Pixel(uint16_t x, uint16_t y) : x(x), y(y) {}

Pixel::Pixel(const Point& p) : x(std::round(p.x)), y(std::round(p.y)) {}

bool Pixel::operator==(const Pixel& other) const {
    return x == other.x && y == other.y;
}

std::ostream& operator<<(std::ostream& os, const Pixel& pixel) {
    os << "[" << pixel.x << ", " << pixel.y << "]";
    return os;
}

