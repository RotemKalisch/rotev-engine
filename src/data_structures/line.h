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
    double get_x(double y) const;
    double get_y(double x) const;

private:
    const Point m_reference;
    double m_slope;
    double m_slope_inv; // overcoming "inf" cases
};
