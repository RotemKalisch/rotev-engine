#include <data_structures/object.h>

Object::Object(
    std::vector<Point> vertices,
    std::vector<std::vector<size_t>> faces,
    std::vector<color_t> colors
) : 
    m_vertices(std::move(vertices)), 
    m_faces(std::move(faces)), 
    m_colors(std::move(colors))
{}

std::vector<Triangle> Object::get_faces() {
    std::vector<Triangle> triangles;
    for (const std::vector<size_t>& face : m_faces) {
        triangles.emplace_back(
            m_vertices[face[0]],
            m_vertices[face[1]],
            m_vertices[face[2]]);
    }
    return triangles;
}

Point& Object::operator[](size_t index) {
    return m_vertices[index];
}

const Point& Object::operator[](size_t index) const {
    return m_vertices[index];
}

const color_t& Object::get_color(size_t index) const {
    return m_colors[index];
}

size_t Object::vertices_amount() const {
    return m_vertices.size();
}

size_t Object::faces_amount() const {
    return m_faces.size();
}

