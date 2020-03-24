#include <iostream>

#include <data_structures/triangle.h>
#include <renderer/renderer.h>

int main() {
    std::shared_ptr<Point> p1 = std::make_shared<Point>(0.0, 0.0, 0.0);
    std::shared_ptr<Point> p2 = std::make_shared<Point>(0.0, 100.0, 0.0);
    std::shared_ptr<Point> p3 = std::make_shared<Point>(100.0, 0.0, 0.0);
    Triangle triangle(p1, p2, p3);
    std::vector<Pixel> pixels = triangle.pixels();
    Renderer renderer = create_renderer("example", 1920 / 2, 984 / 2);
    renderer.lock();
    for (Pixel& pixel : pixels) {
        renderer.fill_pixel(pixel.x, pixel.y, 0xFFFFFFFF);
    }
    renderer.unlock();
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

