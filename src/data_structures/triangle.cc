#include "triangle.h"

Triangle::Triangle(std::shared_ptr<const Point> p1, std::shared_ptr<const Point> p2, std::shared_ptr<const Point> p3) :
    vertices{p1, p2, p3}
{}

std::shared_ptr<const Point> Triangle::operator[](int index) {
    return vertices[index];
}
