#include <gtest/gtest.h>

#include <algorithm>

#include <data_structures/triangle.h>

#define EXPECT_ITEM_IN_VECTOR(x, vec) EXPECT_TRUE(item_in_vector(x, vec))

template<class T>
bool item_in_vector(const T& item, const std::vector<T>& vector) {
    return vector.end() != std::find(vector.begin(), vector.end(), item);
}

TEST(Triangle, pixels_degenerate_triangle) {
    Point p1 (0.0, 0.0, 0.0);
    Point p2 (5.0, 3.0, 7.0);
    Triangle t(p1, p2, p2);
    EXPECT_EQ(0, t.pixels().size());
}

TEST(Triangle, pixels_sanity) {
    double x = 104;
    double y = 1905;
    Point p1 (0.0, 0.0, 0.0);
    Point p2 (x, 0.0, 0.0);
    Point p3 (0.0, y, 0.0);
    Triangle t(p1, p2, p3);
    std::vector<Pixel> pixels = t.pixels();
    for (const Pixel& pixel: pixels) {
        EXPECT_TRUE(pixel.x >= 0 && pixel.x <= x);
        EXPECT_TRUE(pixel.y >= 0 && pixel.y <= y);
    }
}

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
    for (const Pixel& p: t.pixels()) {
        double z = t.interpolate_z(p.x, p.y);
        EXPECT_TRUE(z >= z1 && z <= z3);
    }
 
}

