#pragma once

#include <string>

#include <utils/types.h>

#include <SDL2/SDL.h>

struct Renderer {
public:
    Renderer(const screen_t width, const screen_t height, SDL_Window* window,
            SDL_Renderer* renderer, SDL_Texture* texture);

    /// This destructor is being called to clean up sdl environment
    ~Renderer();

    void fill_pixel(screen_t x, screen_t y, color_t color);

    /// Call this function after unlock.
    void display();

private:
    
    /// These functions are for sdl internals.
    void lock();
    void unlock();

    const screen_t m_width;
    const screen_t m_height;
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    SDL_Texture* m_texture;

    /**
     * The actual pixels used by SDL.
     * The format is RGBA8888 - 32 bit per pixel.
     */
    color_t* m_pixels;
};

Renderer create_renderer(const std::string& title, screen_t width,
        screen_t height, bool fullscreen_mode);

