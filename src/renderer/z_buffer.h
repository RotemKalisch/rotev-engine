#pragma once

#include <utils/types.h>

template <class Renderer>
struct ZBuffer {
public:
    ZBuffer(screen_t width, screen_t height, Renderer renderer) :
        m_width(width),
        m_height(height),
        m_renderer(std::move(renderer)),
        m_z_values((size_t)m_width * m_height)
{}

    void render_pixel(screen_t x, screen_t y, double z, color_t color) {
        size_t index = (size_t)y * m_width + x;
        if (z < m_z_values[index] && z > 0) {
            m_z_values[index] = z;
            m_renderer.fill_pixel(x, y, color);
        }
    }

    void reset() {
        std::fill(m_z_values.begin(), m_z_values.end(), 0.0);
    }

private:
    screen_t m_width;
    screen_t m_height;
    Renderer m_renderer;
    std::vector<double> m_z_values;
};
