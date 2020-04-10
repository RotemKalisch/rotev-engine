#pragma once

#include <utils/types.h>
#include <data_structures/point.h>
#include <data_structures/object.h>

struct Projector {
public:
    Projector(screen_t width, screen_t height);
    Point operator()(const Point& point) const;
    Object operator()(const Object& point) const;

private:
    double depth_projection(double val, double z) const;

    screen_t m_width_half;
    screen_t m_height_half;
};
