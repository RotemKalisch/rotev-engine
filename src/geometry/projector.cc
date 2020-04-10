#include <geometry/projector.h>
#include <cmath>

Projector::Projector(screen_t width, screen_t height) :
    m_width_half(width / 2), m_height_half(height / 2)
{}

Point Projector::operator()(const Point& point) const {
    return Point(
        depth_projection(point.x, point.z),
        depth_projection(point.y, point.z),
        point.z
    );
}

Object Projector::operator()(const Object& object) const {
    Object retval(object);
    for (size_t i = 0; i < retval.vertices_amount(); ++i) {
        retval[i] = this->operator()(retval[i]);
    }
    return retval;
}

double Projector::depth_projection(double val, double z) const {
    return val / z;
}

