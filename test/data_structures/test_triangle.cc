#include <gtest/gtest.h>
#include <algorithm>

#include <rasterization/rasterizer.h>

#include <data_structures/triangle.h>

TEST(Triangle, interpolate_z_sanity) {
    double x = 104;
    double y = 1905;
    double z1 = 1.7;
    double z2 = 2.3;
    double z3 = 3.9;
    Point p1 (0.0, 0.0, z1);
    Point p2 (x, 0.0, z2);
    Point p3 (0.0, y, z3);
    Triangle t(p1, p2, p3);
    for (const Pixel& p: Rasterizer::rasterize(t)) {
        double z = t.interpolate_z(p.x, p.y);
        EXPECT_TRUE(z >= z1 && z <= z3);
    }
}

TEST(Triangle, interpolate_z_triangle_points) {
    double x = 104;
    double y = 1905;
    double z1 = 1.7;
    double z2 = 2.3;
    double z3 = 3.9;
    std::array<Point, 3> points = {Point(0.0, 0.0, z1), Point(x, 0.0, z2), Point(0.0, y, z3)};
    Triangle t(points[0], points[1], points[2]);
    for (int i = 0; i < 2; ++i) {
        EXPECT_DOUBLE_EQ(points[i].z, t.interpolate_z(points[i].x, points[i].y));
    }
}
