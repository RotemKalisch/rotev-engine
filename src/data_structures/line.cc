#include "line.h"

Line::Line(const Point p1, const Point p2) :
    m_reference(p1), m_slope_inv((p1.x - p2.x) / (p1.y - p2.y)) {}

double Line::get_x(double y) {
    return m_reference.x + (y - m_reference.y) * m_slope_inv;
}

double Line::get_y(double x) {
    return m_reference.y + (x - m_reference.x) / m_slope_inv;
}
