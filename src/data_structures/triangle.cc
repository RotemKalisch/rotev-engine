#include <algorithm>
#include <cmath>

#include "line.h"
#include "triangle.h"

Triangle::Triangle(
    std::shared_ptr<const Point> p1,
    std::shared_ptr<const Point> p2,
    std::shared_ptr<const Point> p3
) :
    m_vertices{p1, p2, p3}
{}

std::shared_ptr<const Point> Triangle::operator[](int index) {
    return m_vertices[index];
}

std::vector<Pixel> Triangle::pixels() const {
    std::vector<Pixel> pixels;
    //auto vertices_sorted = get_sorted_vertices();
    //Line longest = Line(vertices_sorted[0], vertices_sorted[2]);
    // TODO: implement tomorrow rotem. I believe in you :) <3
    return pixels;
}

std::array<Point, Triangle::VERTICES> Triangle::get_sorted_vertices() const {
    std::array<Point, Triangle::VERTICES> vertices = 
        {*m_vertices[0], *m_vertices[1], *m_vertices[2]};
    std::sort(vertices.begin(), vertices.end(),
            [](const Point& p1, const Point& p2) { return p1.y < p2.y; });
    return vertices;
}
