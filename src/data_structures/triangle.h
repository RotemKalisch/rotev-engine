#pragma once

#include <array>
#include <vector>
#include <memory>

#include "point.h"
#include "pixel.h"

struct Triangle {
public:
    static constexpr int VERTICES = 3;

    Triangle(std::shared_ptr<const Point> p1, std::shared_ptr<const Point> p2,
            std::shared_ptr<const Point> p3);

    std::shared_ptr<const Point> operator[](int index);

    /**
     * Function returns all pixels inside the triangle using scan convention.
     * Complexity is o(|pixels|)
     */
    std::vector<Pixel> pixels() const;

private:
    /// Returns the vertices of the triangle, ordered by y values.
    std::array<Point, VERTICES> get_sorted_vertices() const;

    std::array<std::shared_ptr<const Point>, VERTICES> m_vertices;
};
