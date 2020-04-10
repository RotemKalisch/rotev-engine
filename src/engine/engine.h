#pragma once

#include <data_structures/object.h>
#include <geometry/projector.h>
#include <rasterization/rasterizer.h>
#include <rasterization/z_buffer.h>
#include <renderer/renderer.h>

struct Engine {
public:
    Engine(std::string title, size_t width, size_t height, bool fullscreen);
    void insert(Object object);

    Object& operator[](size_t index);
    const Object& operator[](size_t index) const;
    size_t size() const;

    void display();

private:
    void display_object(size_t index);

    size_t m_width;
    size_t m_height;

    Projector m_projector;
    ZBuffer m_z_buffer;
    Renderer m_renderer;
    std::vector<Object> m_objects;
};

