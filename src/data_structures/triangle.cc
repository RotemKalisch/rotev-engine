#include <cmath>

#include "triangle.h"

Triangle::Triangle(std::shared_ptr<const Point> p1, std::shared_ptr<const Point> p2, std::shared_ptr<const Point> p3) :
    vertices{p1, p2, p3}
{}

std::shared_ptr<const Point> Triangle::operator[](int index) {
    return vertices[index];
}

std::vector<Pixel> Triangle::pixels() const {
    std::vector<Pixel> pixels;
    Pixel highest_pixel(*vertices[0]);
    pixels.push_back(highest_pixel);
    return pixels;
}
