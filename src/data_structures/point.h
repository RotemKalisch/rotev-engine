#pragma once

#include <iostream>

struct Point {
public:
    Point(double x, double y, double z);
    /// Sometimes we only care for 2d points
    Point(double x, double y);
    double x;
    double y;
    double z;
};

std::ostream& operator<<(std::ostream& os, const Point& p);

