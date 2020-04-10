#pragma once

#include <data_structures/triangle.h>
#include <utils/types.h>

struct Object {
public:

    /**
     * faces is a vector of 3-points indices vector.
     * each item (of type 3-points indices vector) represents the triangle's points.
     */
    Object(
        std::vector<Point> vertices,
        std::vector<std::vector<size_t>> faces,
        std::vector<color_t> colors // for now assuming 1 color per face
    );

    std::vector<Triangle> get_faces();

    Point& operator[](size_t index);
    const Point& operator[](size_t index) const;
    const color_t& get_color(size_t index) const;
    
    size_t vertices_amount() const;
    size_t faces_amount() const;

private:
    std::vector<Point> m_vertices;
    std::vector<std::vector<size_t>> m_faces;
    std::vector<color_t> m_colors;
};

