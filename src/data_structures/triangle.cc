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
    auto vertices_sorted = get_sorted_vertices();
    Line longest = Line(vertices_sorted[0], vertices_sorted[2]);
    Line upper = Line(vertices_sorted[0], vertices_sorted[1]);
    Line lower = Line(vertices_sorted[1], vertices_sorted[2]);
    Pixel top_pixel(vertices_sorted[0]);
    Pixel middle_pixel(vertices_sorted[1]);
    Pixel bottom_pixel(vertices_sorted[2]);
    Line* left_upper = &longest;
    Line* left_lower = &longest;
    Line* right_upper = &upper;
    Line* right_lower = &lower;

    if (bottom_pixel.x > middle_pixel.x) {
        left_upper = &upper;
        left_lower = &lower;
        right_upper = &longest;
        right_lower = &longest;
    }

    for (uint16_t y = top_pixel.y; y < middle_pixel.y; ++y) {
        for (uint16_t x = std::round(left_upper->get_x(y)); x < std::round(right_upper->get_x(y)); ++x) {
            pixels.push_back(Pixel(x, y));
        }
    }
    for (uint16_t y = middle_pixel.y; y < bottom_pixel.y; ++y) {
        for (uint16_t x = std::round(left_lower->get_x(y)); x < std::round(right_lower->get_x(y)); ++x) {
            pixels.push_back(Pixel(x, y));
        }
    }
    return pixels;
}

std::array<Point, Triangle::VERTICES> Triangle::get_sorted_vertices() const {
    std::array<Point, Triangle::VERTICES> vertices = 
        {*m_vertices[0], *m_vertices[1], *m_vertices[2]};
    std::sort(vertices.begin(), vertices.end(),
            [](const Point& p1, const Point& p2) { return p1.y < p2.y; });
    return vertices;
}
