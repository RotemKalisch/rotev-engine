#include <engine/engine.h>

Engine::Engine(std::string title, size_t width, size_t height, bool fullscreen) :
    m_width(width),
    m_height(height),
    m_projector(width, height),
    m_z_buffer(width, height),
    m_renderer(create_renderer(title, width, height, fullscreen))
{}

void Engine::insert(Object object) {
    m_objects.emplace_back(std::move(object));
}

Object& Engine::operator[](size_t index) {
    return m_objects[index];
}

const Object& Engine::operator[](size_t index) const {
    return m_objects[index];
}

size_t Engine::size() const {
    return m_objects.size();
}

void Engine::display() {
    for (size_t i = 0; i < m_objects.size(); ++i) {
        display_object(i);
    }
    m_renderer.display();
}

void Engine::display_object(size_t index) {
    Object projected_object = m_projector(m_objects[index]);
    std::vector<Triangle> projected_faces = projected_object.get_faces();
    for (size_t i = 0; i < projected_faces.size(); ++i) {
        const Triangle& triangle = projected_faces[i];
        color_t color = projected_object.get_color(i);
        std::vector<Pixel> pixels = Rasterizer::rasterize(triangle);
        for (Pixel& pixel : pixels) {
            double z = triangle.interpolate_z(pixel.x, pixel.y);
            if (m_z_buffer.render_pixel(pixel.x, pixel.y, z)) {
                m_renderer.fill_pixel(pixel.x, pixel.y, color);
            }
        }
    }
}

