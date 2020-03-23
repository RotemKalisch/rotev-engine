#include <iostream>

#include <data_structures/triangle.h>

int main() {
    std::shared_ptr<Point> p1 = std::make_shared<Point>(3.5, 4.0, 5.0);
    std::shared_ptr<Point> p2 = std::make_shared<Point>(1.5, 3.0, 7.0);
    std::shared_ptr<Point> p3 = std::make_shared<Point>(5.0, 2.0, 3.5);
    Triangle triangle(p1, p2, p3);
    for (int i = 0; i < Triangle::VERTICES; ++i) {
        std::cout << *(triangle[i]) << std::endl;
    }
}
