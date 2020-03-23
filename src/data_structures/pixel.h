#pragma once

#include <iostream>

#include "point.h"

struct Pixel {
public:
    Pixel(uint16_t x, uint16_t y);
    Pixel(const Point& p);
    uint16_t x;
    uint16_t y;
};

std::ostream& operator<<(std::ostream& os, const Pixel& pixel);

