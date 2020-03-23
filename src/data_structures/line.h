#pragma once

#include "point.h"

/**
 * This class represents a 2D line.
 * NOTICE: Z values are ignored in point. This is because this class is
 * used during the projection stage of the graphics pipeline.
 */
struct Line {
public:
    Line(const Point p1, const Point p2);
    double get_x(double y);
    double get_y(double x);

private:
    const Point m_reference;
    double m_slope_inv;
};
