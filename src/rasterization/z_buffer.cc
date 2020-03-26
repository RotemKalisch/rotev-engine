#include <algorithm>

#include "z_buffer.h"

ZBuffer::ZBuffer(screen_t width, screen_t height) :
        m_width(width),
        m_height(height),
        m_z_values((size_t)m_width * m_height, std::numeric_limits<double>::max())
{}

bool ZBuffer::render_pixel(screen_t x, screen_t y, double z) {
    size_t index = static_cast<size_t>(y) * m_width + x;
    if (is_visible(index, z)) {
        m_z_values[index] = z;
        return true;
    }
    return false;
}

void ZBuffer::reset() {
    std::fill(m_z_values.begin(), m_z_values.end(), std::numeric_limits<double>::max());
}

bool ZBuffer::is_visible(size_t index, double z) {
    return z < m_z_values[index] && z > 0;
}
