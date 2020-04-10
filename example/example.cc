#include <iostream>

#include <engine/engine.h>

color_t red = 0xFF0000FF;
color_t yellow = 0xFFFF00FF;
color_t blue = 0x0000FFFF;

int main() {
    size_t width = 1920;
    size_t height = 984;
    Engine engine ("example", width, height, true);
    std::vector<Point> points;
    points.emplace_back(100.0, 100.0, 1.0);
    points.emplace_back(200.0, 100.0, 1.0);
    points.emplace_back(100.0, 200.0, 1.0);
    points.emplace_back(200.0, 200.0, 1.0);
    points.emplace_back(100.0, 100.0, 1.5);
    points.emplace_back(200.0, 100.0, 1.5);
    points.emplace_back(100.0, 200.0, 1.5);
    points.emplace_back(200.0, 200.0, 1.5);
    std::vector<std::vector<size_t>> faces = {
        {0, 1, 2}, {3, 1, 2},
        {0, 1, 4}, {5, 1, 4},
        {0, 2, 4}, {6, 2, 4},
        {1, 3, 5}, {7, 3, 5},
        {2, 3, 6}, {7, 3, 6},
        {4, 5, 6}, {7, 5, 6}
    };
    std::vector<color_t> colors = {red, red, blue, blue, yellow, yellow, yellow, yellow, blue, blue, red, red};
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

