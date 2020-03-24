#include <gtest/gtest.h>

#include <cmath>

#include <data_structures/line.h>

#define EXPECT_DOUBLES_EQ(x, y) EXPECT_TRUE(equals(x, y))

static constexpr double EPSILON = 10e-4;

bool equals(double a, double b) {
    return fabs(a - b) < EPSILON;
}

TEST(Line, point_values) {
    Point p1(6.3, 5.1);
    Point p2(9.2, 8.3);
    Line line(p1, p2);
    EXPECT_DOUBLES_EQ(p1.x, line.get_x(p1.y));
    EXPECT_DOUBLES_EQ(p1.y, line.get_y(p1.x));
    EXPECT_DOUBLES_EQ(p2.x, line.get_x(p2.y));
    EXPECT_DOUBLES_EQ(p2.y, line.get_y(p2.x));
}

TEST(Line, correctness) {
    Point p1(0.0, 0.0);
    Point p2(1.0, 2.0);
    Line line(p1, p2);
    EXPECT_DOUBLES_EQ(5.0, line.get_y(2.5));
    EXPECT_DOUBLES_EQ(2.5, line.get_x(5.0));
}

TEST(Line, vertical) {
    Point p1(1.0, 0.0);
    Point p2(1.0, 1.0);
    Line line(p1, p2);
    EXPECT_DOUBLES_EQ(1.0, line.get_x(17.6));
}

TEST(Line, horizontal) {
    Point p1(0.0, 1.0);
    Point p2(1.0, 1.0);
    Line line(p1, p2);
    EXPECT_DOUBLES_EQ(1.0, line.get_x(17.6));
}

