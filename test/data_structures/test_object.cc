#include <gtest/gtest.h>

#include <data_structures/object.h>

#define EXPECT_EMPTY(vec) EXPECT_EQ(0, vec.size())

TEST(Object, vertices_amount_empty) {
    Object object({}, {}, {});
    EXPECT_EQ(0, object.vertices_amount());
}

TEST(Object, vertices_amount_not_empty) {
    std::vector<Point> vertices = {Point(0.0, 1.0, 2.0)};
    Object object(vertices, {}, {});
    EXPECT_EQ(vertices.size(), object.vertices_amount());
}

TEST(Object, faces_amount_empty) {
    Object object({}, {}, {});
    EXPECT_EQ(0, object.faces_amount());
}

TEST(Object, faces_amount_not_empty) {
    std::vector<std::vector<size_t>> faces = {{0, 1, 2}, {3, 4, 5}};
    Object object({}, faces, {});
    EXPECT_EQ(faces.size(), object.faces_amount());
}

TEST(Object, get_faces_empty) {
    Object object({}, {}, {});
    EXPECT_EMPTY(object.get_faces());
}

TEST(Object, get_faces_not_empty) {
    std::vector<Point> points;
    points.emplace_back(1.0, 0.0, 0.0);
    points.emplace_back(0.0, 1.0, 0.0);
    points.emplace_back(0.0, 0.0, 1.0);
    std::vector<std::vector<size_t>> faces = {{0, 1, 2}};
    std::vector<Triangle> triangles;
    for (size_t i = 0; i < faces.size(); ++i) {
        triangles.emplace_back(
            points[faces[i][0]],
            points[faces[i][1]],
            points[faces[i][2]]
        );
    }
    Object object(points, faces, {0xFF0000FF});
    EXPECT_EQ(triangles, object.get_faces());
}

