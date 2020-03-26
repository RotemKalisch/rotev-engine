#include <gtest/gtest.h>

#include <rasterization/z_buffer.h>

TEST(ZBuffer, non_initialized) {
    ZBuffer buffer(1, 1);
    double huge_z = 500000;
    EXPECT_TRUE(buffer.render_pixel(0, 0, huge_z));
}

TEST(ZBuffer, overwrite) {
    ZBuffer buffer(1, 1);
    double z1 = 1.7;
    double z2 = z1 + 3.5;
    EXPECT_TRUE(buffer.render_pixel(0, 0, z2));
    EXPECT_TRUE(buffer.render_pixel(0, 0, z1));
}

TEST(ZBuffer, reject) {
    ZBuffer buffer(1, 1);
    double z1 = 1.7;
    double z2 = z1 + 3.5;
    EXPECT_TRUE(buffer.render_pixel(0, 0, z1));
    EXPECT_FALSE(buffer.render_pixel(0, 0, z2));
}

