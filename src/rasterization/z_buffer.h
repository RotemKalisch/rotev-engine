#pragma once

#include <limits>

#include <utils/types.h>

struct ZBuffer {
public:
    ZBuffer(screen_t width, screen_t height);
    bool render_pixel(screen_t x, screen_t y, double z);
    void reset();

private:
    bool is_visible(size_t index, double z);

    screen_t m_width;
    screen_t m_height;
    std::vector<double> m_z_values;
};
