#include "point.h"

#include <cmath>

bool doubles_eq(double a, double b) {
    return abs(a - b) < 0.00001;
}

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

Point::Point(double x, double y) : x(x), y(y) {}

bool Point::operator==(const Point& other) const {
    return doubles_eq(x, other.x) && doubles_eq(y, other.y) && doubles_eq(z, other.z);
}

std::ostream& operator<<(std::ostream& os, const Point& p) { 
    os << "{" << p.x << ", " << p.y << ", " << p.z << "}";
    return os;
} 
