#include "RenderWindow.hpp"
#include "../exceptions/Exceptions.hpp"

namespace sdlu
{
    RenderWindow::RenderWindow()
    {
        m_pWindow = nullptr;
        m_pRenderer = nullptr;
    }

    RenderWindow::RenderWindow(Vector2u dimension, const std::string& title,
        Uint32 windowFlags, Uint32 rendererFlags)
    {
        m_pWindow = nullptr;
        m_pRenderer = nullptr;
        Create(dimension, title, windowFlags, rendererFlags);
    }

    RenderWindow::~RenderWindow()
    {
        Close();
    }

    void RenderWindow::Create(Vector2u dimension, const std::string& title,
        Uint32 windowFlags, Uint32 rendererFlags)
    {
        // Don't create a window when it already exists
        if (!IS_NULLPTR(m_pWindow)) return;

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
        // Don't destroy a window that doesn't exist
        if (IS_NULLPTR(m_pWindow)) return;

        SDL_DestroyRenderer(m_pRenderer);
        m_pRenderer = nullptr;

        SDL_DestroyWindow(m_pWindow);
        m_pWindow = nullptr;

        OnClose();
    }

    bool RenderWindow::IsOpen()
    {
        return (!SDL_GetWindowID(m_pWindow) ? false : true);
    }

    bool RenderWindow::PollEvent(SDL_Event* event)
    {
        // Handle events before the user in case a derived
        // class decides to block the event.
        while (SDL_PollEvent(event))
        {
            switch(event->window.event)
            {
                case SDL_WINDOWEVENT_RESIZED: if (!OnResize()) return true; break;
                default: return true;
            }
        }

        event = NULL;
        return false;
    }

    bool RenderWindow::WaitEvent(SDL_Event* event)
    {
        while (!PollEvent(event)) continue;
        return true;
    }

    Vector2i RenderWindow::GetPosition()
    {
        int x = 0, y = 0;
        SDL_GetWindowPosition(m_pWindow, &x, &y);
        return Vector2i(x, y);
    }

    void RenderWindow::SetPosition(Vector2i position)
    {
        SDL_SetWindowPosition(m_pWindow, position.x, position.y);
    }

    void RenderWindow::SetPosition(int x, int y)
    {
        SDL_SetWindowPosition(m_pWindow, x, y);
    }

    Vector2u RenderWindow::GetSize()
    {
        int x = 0, y = 0;
        SDL_GetWindowSize(m_pWindow, &x, &y);
        return Vector2u(x, y);
    }

    void RenderWindow::SetSize(Vector2u size)
    {
        SDL_SetWindowSize(m_pWindow, size.x, size.y);
    }

    void RenderWindow::SetSize(unsigned int width, unsigned int height)
    {
        SDL_SetWindowSize(m_pWindow, width, height);
    }

    std::string RenderWindow::GetTitle()
    {
        return SDL_GetWindowTitle(m_pWindow);
    }

    void RenderWindow::SetTitle(std::string title)
    {
        SDL_SetWindowTitle(m_pWindow, title.c_str());
    }
}