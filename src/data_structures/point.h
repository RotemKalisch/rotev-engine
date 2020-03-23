#pragma once

#include <iostream>

struct Point {
public:
    Point(double x, double y, double z);
    double x;
    double y;
    double z;
};

std::ostream& operator<<(std::ostream& os, const Point& p);

