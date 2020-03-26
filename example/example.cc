#include <iostream>

#include <data_structures/triangle.h>
#include <renderer/renderer.h>
#include <renderer/z_buffer.h>

int main() {
    Point p1(0.0, 0.0, 0.0);
    Point p2(0.0, 100.0, 0.0);
    Point p3(100.0, 0.0, 0.0);
    Triangle triangle(p1, p2, p3);
    std::vector<Pixel> pixels = triangle.pixels();
    Renderer renderer = create_renderer("example", 1920, 984, true);
    for (Pixel& pixel : pixels) {
        renderer.fill_pixel(pixel.x, pixel.y, 0xFFFFFFFF);
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

