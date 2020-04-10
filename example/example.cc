#include <iostream>

#include <engine/engine.h>

color_t color(screen_t z) {
    color_t retval =  0xFF0000FF | ((0xFF - z) << 16);
    return retval;
}

int main() {
    size_t width = 1920;
    size_t height = 984;
    Engine engine ("example", width, height, true);
    std::vector<Point> points;
    points.emplace_back(0.0, 0.0, 0.1);
    points.emplace_back(0.0, 300.0, 255.0);
    points.emplace_back(300.0, 0.0, 127.0);
    std::vector<std::vector<size_t>> faces = {{0, 1, 2}};
    std::vector<color_t> colors = {0xFF0000FF};
    Object object (std::move(points), std::move(faces), std::move(colors));
    engine.insert(std::move(object));
    engine.display();

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

