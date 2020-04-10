#pragma once

#include <data_structures/triangle.h>
#include <data_structures/pixel.h>

namespace Rasterizer {

    /**
     * Function returns all pixels inside the triangle using scan convention.
     * Complexity is o(|pixels|)
     */
    std::vector<Pixel> rasterize(const Triangle& triangle);

}

