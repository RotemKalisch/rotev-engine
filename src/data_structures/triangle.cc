#include <algorithm>
#include <cmath>

#include "line.h"
#include "triangle.h"

Triangle::Triangle(
    const Point& p1,
    const Point& p2,
    const Point& p3
) :
    m_vertices{p1, p2, p3}
{}

const Point& Triangle::operator[](int index) {
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

    std::array<std::reference_wrapper<Line>, 2> left_bounds = {longest, longest};
    std::array<std::reference_wrapper<Line>, 2> right_bounds = {upper, lower};

    if (bottom_pixel.x > middle_pixel.x) {
        std::swap(left_bounds, right_bounds);
    }

    for (int i = 0; i < 2; ++i) {
        for (screen_t y = vertices_sorted[i].get().y; y < vertices_sorted[i+1].get().y; ++y) {
            for (
                screen_t x = std::round(left_bounds[i].get().get_x(y));
                x < std::round(right_bounds[i].get().get_x(y));
                ++x
            ) {
                pixels.push_back(Pixel(x, y));
            }
        }
    }
    return pixels;
}

double Triangle::interpolate_z(screen_t x, screen_t y) {
    /*
     * Barycentric Coordinates interpolation.
     * Read more: https://codeplea.com/triangular-interpolation
     */
    #define x(i) m_vertices[i].get().x
    #define y(i) m_vertices[i].get().y
    #define z(i) m_vertices[i].get().z
    double x_x2 = x - x(2);
    double y_y2 = y - y(2);
    double denominator = (y(1)-y(2))*(x(0)-x(2)) + (x(2)-x(1))*(y(0)-y(2));
    double w0 = (y(1)-y(2))*x_x2 + (x(2)-x(1))*y_y2;
    double w1 = (y(2)-y(0))*x_x2 + (x(0)-x(2))*y_y2;
    double w2 = denominator - w0 - w1;
    return (w0*z(0) + w1*z(1) + w2*z(2)) / denominator;
    #undef x
    #undef y
    #undef z
}

std::array<std::reference_wrapper<const Point>, Triangle::VERTICES> Triangle::get_sorted_vertices() const {
    std::array<std::reference_wrapper<const Point>, Triangle::VERTICES> vertices = 
        {m_vertices[0], m_vertices[1], m_vertices[2]};
    std::sort(vertices.begin(), vertices.end(),
            [](const Point& p1, const Point& p2) { return p1.y < p2.y; });
    return vertices;
}
