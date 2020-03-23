#include "point.h"

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

std::ostream& operator<<(std::ostream& os, const Point& p) { 
    os << "{" << p.x << ", " << p.y << ", " << p.z << "}";
    return os;
} 
