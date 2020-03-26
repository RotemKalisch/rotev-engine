#pragma once

#include <array>
#include <vector>
#include <functional>

#include "point.h"
#include "pixel.h"

struct Triangle {
public:
    static constexpr int VERTICES = 3;

    Triangle(const Point& p1, const Point& p2, const Point& p3);

    const Point& operator[](int index);

    /**
     * Function returns all pixels inside the triangle using scan convention.
     * Complexity is o(|pixels|)
     */
    std::vector<Pixel> pixels() const;

    /// Function returns the z value for a pixel inside the triangle.
    double interpolate_z(screen_t x, screen_t y);

private:

    /// Returns the vertices of the triangle, ordered by y values.
    std::array<std::reference_wrapper<const Point>, VERTICES> get_sorted_vertices() const;

    std::array<std::reference_wrapper<const Point>, VERTICES> m_vertices;
};
