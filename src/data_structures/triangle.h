#pragma once

#include <array>
#include <memory>

#include "point.h"

struct Triangle {
public:
    static constexpr int VERTICES = 3;

    Triangle(std::shared_ptr<const Point> p1, std::shared_ptr<const Point> p2,
            std::shared_ptr<const Point> p3);
    std::shared_ptr<const Point> operator[](int index);

private:
    std::array<std::shared_ptr<const Point>, VERTICES> vertices;
};
