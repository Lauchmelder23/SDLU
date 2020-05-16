#include "RenderWindow.hpp"

#define IS_NULLPTR( x ) (x == nullptr)

namespace sdlu
{
    RenderWindow::RenderWindow()
    {
    }

    RenderWindow::RenderWindow(Vector2u dimension, const std::string& title,
        Uint32 windowFlags, Uint32 rendererFlags)
    {
        Create(dimension, title, windowFlags, rendererFlags);
    }

    void RenderWindow::Create(Vector2u dimension, const std::string& title,
        Uint32 windowFlags, Uint32 rendererFlags)
    {
        // Leave the function if the window or render already exist
        if (!IS_NULLPTR(m_pWindow) ||
            !IS_NULLPTR(m_pRenderer))
        {
            return;
        }

        m_pWindow = SDL_CreateWindow(title.c_str(),
                                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    dimension.x, dimension.y,
                                    windowFlags);
        if (IS_NULLPTR(m_pWindow))
        {
            // TODO: Implement exception
            return
        }

        m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, rendererFlags);
        if (IS_NULLPTR(m_pRenderer))
        {
            // TODO: Implement exception
            return
        }
    }
}