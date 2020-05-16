#include "RenderWindow.hpp"
#include "../exceptions/Exceptions.hpp"

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

    RenderWindow::~RenderWindow()
    {
        Close();
    }

    void RenderWindow::Create(Vector2u dimension, const std::string& title,
        Uint32 windowFlags, Uint32 rendererFlags)
    {
        m_pWindow = SDL_CreateWindow(title.c_str(),
                                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    dimension.x, dimension.y,
                                    windowFlags);
        THROW_IF(IS_NULLPTR(m_pWindow),
            ObjectCreationException("Failed to create SDL_Window."));

        m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, rendererFlags);
        THROW_IF(IS_NULLPTR(m_pRenderer),
            ObjectCreationException("Failed to create SDL_Renderer."));

        OnCreate();
    }

    void RenderWindow::Close()
    {
        SDL_DestroyWindow(m_pWindow);

        OnClose();
    }

    bool RenderWindow::IsOpen()
    {
        return !IS_NULLPTR(m_pWindow);
    }

    bool RenderWindow::PollEvent(SDL_Event& event)
    {
        // Handle events before the user in case a derived
        // class decides to block the event.
        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_WINDOWEVENT_RESIZED: OnResize() ? break : return true;
                default: return true;
            }
        }

        event = NULL;
        return false;
    }

    bool RenderWindow::WaitEvent(SDL_Event& event)
    {
        while (!PollEvent(event)) continue;
    }
}