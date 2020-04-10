#include <gtest/gtest.h>

#include <algorithm>

#include <data_structures/triangle.h>
#include <rasterization/rasterizer.h>

TEST(Rasterizer, pixels_degenerate_triangle) {
    Point p1 (0.0, 0.0, 0.0);
    Point p2 (5.0, 3.0, 7.0);
    Triangle t(p1, p2, p2);
    EXPECT_EQ(0, Rasterizer::rasterize(t).size());
}

TEST(Rasterizer, pixels_sanity) {
    double x = 104;
    double y = 1905;
    Point p1 (0.0, 0.0, 0.0);
    Point p2 (x, 0.0, 0.0);
    Point p3 (0.0, y, 0.0);
    Triangle t(p1, p2, p3);
    std::vector<Pixel> pixels = Rasterizer::rasterize(t);
    for (const Pixel& pixel: pixels) {
        EXPECT_TRUE(pixel.x >= 0 && pixel.x <= x);
        EXPECT_TRUE(pixel.y >= 0 && pixel.y <= y);
    }
}

