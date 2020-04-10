#pragma once

#include <array>
#include <vector>
#include <functional>

#include <utils/types.h>
#include <data_structures/point.h>

struct Triangle {
public:
    static constexpr int VERTICES = 3;

    Triangle(const Point& p1, const Point& p2, const Point& p3);

    const Point& operator[](int index) const;

    bool operator==(const Triangle& other) const;

    /// Function returns the z value for a pixel inside the triangle.
    double interpolate_z(screen_t x, screen_t y) const;

    /// Returns the vertices of the triangle, ordered by y values.
    std::array<std::reference_wrapper<const Point>, VERTICES> get_sorted_vertices() const;

private:
    std::array<std::reference_wrapper<const Point>, VERTICES> m_vertices;
};

std::ostream& operator<<(std::ostream& os, const Triangle& triangle);

