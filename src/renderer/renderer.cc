#include "renderer_exceptions.h"

#include "renderer.h"

const static int DEFAULT_RENDERING_DRIVER = -1;

Renderer::Renderer(
    const screen_t width,
    const screen_t height,
    SDL_Window* window,
    SDL_Renderer* renderer,
    SDL_Texture* texture
) :
    m_width(width),
    m_height(height),
    m_window(window),
    m_renderer(renderer),
    m_texture(texture),
    m_pixels(nullptr),
    m_pixels_centered(nullptr)
{
    lock(); // RAII
} 

Renderer::~Renderer() {
    unlock();
    SDL_DestroyTexture(m_texture);
    SDL_DestroyRenderer(m_renderer); 
    SDL_DestroyWindow(m_window);
}

/// Function locks the texture and allows pixel changing
void Renderer::lock() {
    int pitch;
    int result = SDL_LockTexture(
            m_texture,
            nullptr, // we lock the entire texture
            reinterpret_cast<void**>(&m_pixels),
            &pitch /* pitch will be stored here. as of now - it is height,
                     therefore it's not used */
        );
    m_pixels_centered = &m_pixels[(m_height/2) * m_width + m_width / 2];
    if (result < 0 || !m_pixels) {
        throw RendererException("SDL_LockTexture failed");
    }
}

/// Function unlocks the texture and allows displaying.
void Renderer::unlock() {
    if (!m_pixels) {
        throw RendererException("SDL_UnlockTexture failed because lock was not invoked");
    }
    SDL_UnlockTexture(m_texture);
    m_pixels = nullptr;
    m_pixels_centered = nullptr;
}

void Renderer::fill_pixel(screen_t x, screen_t y, color_t color) {
    /*
     * Transforming from SDL coordinate system (x left to right, y up to down)
     * to the normal one (x left to right, y down to up)
     */
    m_pixels_centered[y * m_width + x] = color;
}

void Renderer::display() {
    unlock(); // we want to display the texture
    SDL_RenderCopy(m_renderer, m_texture, nullptr, nullptr);
    SDL_RenderPresent(m_renderer);
    SDL_RenderClear(m_renderer);
    lock(); // back to editing mode
}


Renderer create_renderer(
    const std::string& title,
    screen_t width,
    screen_t height,
    bool fullscreen_mode
) {
    uint32_t flags = SDL_WINDOW_SHOWN;
    if (fullscreen_mode) {
        flags |= SDL_WINDOW_FULLSCREEN;
    }
    SDL_Window* window(SDL_CreateWindow(
                title.data(),
                SDL_WINDOWPOS_UNDEFINED, // as of now i dont care about initial
                SDL_WINDOWPOS_UNDEFINED, // position of the window.
                width,
                height,
                flags
                )
            );

    if (!window) {
        throw RendererException("SDL_CreateWindow failed");
    }

    SDL_Renderer* renderer(SDL_CreateRenderer(
                window,
                DEFAULT_RENDERING_DRIVER,
                SDL_RENDERER_ACCELERATED
                )
            );

    if (!renderer) {
        SDL_DestroyWindow(window);
        throw RendererException("SDL_CreateRenderer failed");
    }
    
    SDL_Texture* texture (SDL_CreateTexture(
                renderer, 
                SDL_PIXELFORMAT_RGBA8888,
                SDL_TEXTUREACCESS_STREAMING,
                width,
                height
                )
            );
   
    if (!texture) {
        SDL_DestroyRenderer(renderer); 
        SDL_DestroyWindow(window);
        throw RendererException("SDL_CreateTexture failed");
    }

    return Renderer(width, height, window, renderer, texture);

}
