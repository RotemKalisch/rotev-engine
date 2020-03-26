#include <iostream>

#include <data_structures/triangle.h>
#include <renderer/renderer.h>
#include <renderer/z_buffer.h>

color_t color(screen_t z) {
    color_t retval =  0xFF0000FF | ((0xFF - z) << 16);
    return retval;
}

int main() {
    size_t width = 1920;
    size_t height = 984;
    Renderer renderer = create_renderer("example", width, height, true);
    ZBuffer buffer (width, height);
    Point p1(0.0, 0.0, 0.0);
    Point p2(0.0, 500.0, 255.0);
    Point p3(500.0, 0.0, 127.0);
    std::array<Triangle, 1> triangle = {Triangle(p1, p2, p3)};
    for (int i = 0; i < 1; ++i) {
        std::vector<Pixel> pixels = triangle[i].pixels();
        for (Pixel& pixel : pixels) {
            double z = triangle[i].interpolate_z(pixel.x, pixel.y);
            if (buffer.render_pixel(pixel.x, pixel.y, z)) {
                renderer.fill_pixel(pixel.x, pixel.y, color(z));
            }
        }
    }
    renderer.display();

    bool quit = false;
    SDL_Event e;

    while(!quit) {
        //Handle events on queue
        while(SDL_PollEvent(&e) != 0) {
        //User requests quit
            if(e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }
}

