#include <gtest/gtest.h>

#include <data_structures/triangle.h>

#define EXPECT_ITEM_IN_VECTOR(x, vec) EXPECT_TRUE(item_in_vector(x, vec))

template<class T>
bool item_in_vector(const T& item, std::vector<T> vector) {
    for (const T& vec_item: vector) {
        if (vec_item == item) {
            return true;
        }
    }
    return false;
}

TEST(Triangle, pixels_degenerate_triangle) {
    std::shared_ptr<Point> p1 = std::make_shared<Point>(0.0, 0.0, 0.0);
    std::shared_ptr<Point> p2 = std::make_shared<Point>(5.0, 3.0, 7.0);
    Triangle t(p1, p2, p2);
    EXPECT_EQ(0, t.pixels().size());
}

TEST(Triangle, pixels_sanity) {
    double x = 104;
    double y = 1905;
    std::shared_ptr<Point> p1 = std::make_shared<Point>(0.0, 0.0, 0.0);
    std::shared_ptr<Point> p2 = std::make_shared<Point>(x, 0.0, 0.0);
    std::shared_ptr<Point> p3 = std::make_shared<Point>(0.0, y, 0.0);
    Triangle t(p1, p2, p3);
    std::vector<Pixel> pixels = t.pixels();
    for (const Pixel& pixel: pixels) {
        EXPECT_TRUE(pixel.x >= 0 && pixel.x <= x);
        EXPECT_TRUE(pixel.y >= 0 && pixel.y <= y);
    }
}

