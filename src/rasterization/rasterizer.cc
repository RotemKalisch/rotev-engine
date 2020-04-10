#include <cmath>

#include <data_structures/line.h>

#include "rasterizer.h"

namespace Rasterizer {

    std::vector<Pixel> rasterize(const Triangle& triangle) {
        std::vector<Pixel> pixels;
        auto vertices_sorted = triangle.get_sorted_vertices();
        Line longest = Line(vertices_sorted[0], vertices_sorted[2]);
        Line upper = Line(vertices_sorted[0], vertices_sorted[1]);
        Line lower = Line(vertices_sorted[1], vertices_sorted[2]);
        Pixel top_pixel(vertices_sorted[0]);
        Pixel middle_pixel(vertices_sorted[1]);
        Pixel bottom_pixel(vertices_sorted[2]);

        std::array<std::reference_wrapper<Line>, 2> left_bounds = {longest, longest};
        std::array<std::reference_wrapper<Line>, 2> right_bounds = {upper, lower};

        if (bottom_pixel.x > middle_pixel.x) {
            std::swap(left_bounds, right_bounds);
        }

        for (int i = 0; i < 2; ++i) {
            for (
                screen_t y = vertices_sorted[i].get().y;
                y < static_cast<screen_t>(vertices_sorted[i+1].get().y);
                ++y
            ) {
                for (
                    screen_t x = std::round(left_bounds[i].get().get_x(y));
                    x < std::round(right_bounds[i].get().get_x(y));
                    ++x
                ) {
                    pixels.push_back(Pixel(x, y));
                }
            }
        }
        return pixels;
    }

}

