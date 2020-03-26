#pragma once

#include <limits>

#include <utils/types.h>

struct ZBuffer {
public:
    ZBuffer(screen_t width, screen_t height) :
        m_width(width),
        m_height(height),
        m_z_values((size_t)m_width * m_height, std::numeric_limits<double>::max())
{}

    bool render_pixel(screen_t x, screen_t y, double z) {
        size_t index = static_cast<size_t>(y) * m_width + x;
        if (z < m_z_values[index] && z > 0) {
            m_z_values[index] = z;
            return true;
        }
        return false;
    }

    void reset() {
        std::fill(m_z_values.begin(), m_z_values.end(), std::numeric_limits<double>::max());
    }

private:
    screen_t m_width;
    screen_t m_height;
    std::vector<double> m_z_values;
};
