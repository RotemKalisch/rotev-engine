#pragma once

#include <iostream>

#include <utils/types.h>

#include "point.h"

struct Pixel {
public:
    Pixel(screen_t x, screen_t y);
    Pixel(const Point& p);
    bool operator==(const Pixel& other) const;
    screen_t x;
    screen_t y;
};

std::ostream& operator<<(std::ostream& os, const Pixel& pixel);

