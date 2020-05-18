#include "RenderWindow.hpp"

#include <cstring>

#include <exceptions/Exceptions.hpp>
#include <Util.hpp>

namespace sdlu
{
    RenderWindow::RenderWindow() :
        m_pWindow(nullptr), m_pRenderer(nullptr),
        m_oFramerate(0), m_oTimeSinceLastDisplay(std::chrono::steady_clock::now())
    {

    }

    RenderWindow::RenderWindow(Vector2u dimension, const std::string& title,
        Uint32 windowFlags, Uint32 rendererFlags) :
        RenderWindow()
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
        // Don't create a window when it already exists
        RETURN_IF_NOT_NULLPTR(m_pWindow);

        m_pWindow = SDL_CreateWindow(title.c_str(),
                                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                    dimension.x, dimension.y,
                                    windowFlags);

        THROW_IF(IS_NULLPTR(m_pWindow),
            ObjectCreationException("Failed to create SDL_Window. \nSDL_GetError(): " + std::string(SDL_GetError())));

        m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, rendererFlags);
        THROW_IF(IS_NULLPTR(m_pRenderer),
            ObjectCreationException("Failed to create SDL_Renderer. \nSDL_GetError(): " + std::string(SDL_GetError())));

        OnCreate();
    }

    void RenderWindow::Close()
    {
        // Don't destroy a window that doesn't exist
        RETURN_IF_NULLPTR(m_pWindow);

        SDL_DestroyRenderer(m_pRenderer);
        m_pRenderer = nullptr;

        SDL_DestroyWindow(m_pWindow);
        m_pWindow = nullptr;

        OnClose();
    }

    bool RenderWindow::IsOpen()
    {
        RETURN_IF_NULLPTR(m_pWindow, false);
        return (!SDL_GetWindowID(m_pWindow) ? false : true);
    }

    bool RenderWindow::PollEvent(SDL_Event* event)
    {
        RETURN_IF_NULLPTR(m_pWindow, false);
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
        RETURN_IF_NULLPTR(m_pWindow, Vector2i());

        int x = 0, y = 0;
        SDL_GetWindowPosition(m_pWindow, &x, &y);
        return Vector2i(x, y);
    }

    void RenderWindow::SetPosition(Vector2i position)
    {
        RETURN_IF_NULLPTR(m_pWindow);

        SDL_SetWindowPosition(m_pWindow, position.x, position.y);
    }

    void RenderWindow::SetPosition(int x, int y)
    {
        RETURN_IF_NULLPTR(m_pWindow);

        SDL_SetWindowPosition(m_pWindow, x, y);
    }

    Vector2u RenderWindow::GetSize()
    {
        RETURN_IF_NULLPTR(m_pWindow, Vector2u());

        int x = 0, y = 0;
        SDL_GetWindowSize(m_pWindow, &x, &y);
        return Vector2u(x, y);
    }

    void RenderWindow::SetSize(Vector2u size)
    {
        RETURN_IF_NULLPTR(m_pWindow);

        SDL_SetWindowSize(m_pWindow, size.x, size.y);
    }

    void RenderWindow::SetSize(unsigned int width, unsigned int height)
    {
        RETURN_IF_NULLPTR(m_pWindow);

        SDL_SetWindowSize(m_pWindow, width, height);
    }

    std::string RenderWindow::GetTitle()
    {
        RETURN_IF_NULLPTR(m_pWindow, "");

        return SDL_GetWindowTitle(m_pWindow);
    }

    void RenderWindow::SetTitle(std::string title)
    {
        RETURN_IF_NULLPTR(m_pWindow);

        SDL_SetWindowTitle(m_pWindow, title.c_str());
    }

    SDL_Window* const RenderWindow::GetWindow()
    {
        return m_pWindow;
    }

    SDL_Renderer* const RenderWindow::GetRenderer()
    {
        return m_pRenderer;
    }

    void RenderWindow::Clear(const Color& color)
    {
        RETURN_IF_NULLPTR(m_pWindow);

        SDL_SetRenderDrawColor(m_pRenderer, color.r, color.g, color.b, color.a);
        SDL_RenderClear(m_pRenderer);
    }

    void RenderWindow::Display()
    {
        RETURN_IF_NULLPTR(m_pWindow);

        SDL_RenderPresent(m_pRenderer);

        if (m_oFramerate != 0)
        {
            Uint64 diff = std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::steady_clock::now() - m_oTimeSinceLastDisplay).count();

            if (diff < 1000 / m_oFramerate)
            {
                SDL_Delay(static_cast<Uint32>(1000 / m_oFramerate - diff));
            }
        }

        m_oTimeSinceLastDisplay = std::chrono::steady_clock::now();
    }

    void RenderWindow::SetVisible(bool visible)
    {
        RETURN_IF_NULLPTR(m_pWindow);
        if (visible)
            SDL_ShowWindow(m_pWindow);
        else
            SDL_HideWindow(m_pWindow);
    }

    void RenderWindow::SetVsync(bool vsync)
    {
        // SDL actually doesn't allow you to change the VSync
        // flag of a Renderer after it's been created. This
        // Changes it globally for all other windows
        SDL_GL_SetSwapInterval(vsync);
    }

    void RenderWindow::SetMouseCursorVisible(bool visible)
    {
        SDL_ShowCursor(visible);
    }

    void RenderWindow::SetMouseCursorGrabbed(bool grabbed)
    {
        SDL_SetWindowGrab(m_pWindow, grabbed ? SDL_TRUE : SDL_FALSE);
    }

    void RenderWindow::SetIcon(Uint32 width, Uint32 height, const Uint8* pixels)
    {
        size_t size = static_cast<size_t>(width) * static_cast<size_t>(height) * 4;
        void* _pixels = malloc(size);
        memcpy(_pixels, pixels, size);
        SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom(_pixels,
            width, height, 32, 32 * width,
            SDL_PIXELFORMAT_RGBA8888);

        SDL_SetWindowIcon(m_pWindow, surface);
    }

    void RenderWindow::SetIcon(Uint32 width, Uint32 height, const Uint32* pixels)
    {
        size_t size = static_cast<size_t>(width) * static_cast<size_t>(height) * 4;
        void* _pixels = malloc(size);
        memcpy(_pixels, pixels, size);
        SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom(_pixels,
            width, height, 32, 4 * width,
            SDL_PIXELFORMAT_RGBA8888);

        SDL_SetWindowIcon(m_pWindow, surface);
    }

    void RenderWindow::SetIcon(SDL_Surface* icon)
    {
        SDL_SetWindowIcon(m_pWindow, icon);
    }

    void RenderWindow::SetMaxFramerate(Uint32 max)
    {
        m_oFramerate = max;
    }

    void RenderWindow::SetMouseCursor(SDL_Cursor* cursor)
    {
        SDL_SetCursor(cursor);
    }

    void RenderWindow::SetMouseCursor(SDL_SystemCursor cursor)
    {
        SDL_Cursor* _cursor = SDL_CreateSystemCursor(cursor);
        SDL_SetCursor(_cursor);
    }

    void RenderWindow::SetMouseCursor(SDL_Surface* surface, Vector2u clickspot)
    {
        SDL_Cursor* _cursor = SDL_CreateColorCursor(surface, clickspot.x, clickspot.y);
        SDL_SetCursor(_cursor);
    }

    void RenderWindow::SetMouseCursor(const Uint8* pixels, Vector2u size, Vector2u clickspot)
    {
        size_t _size = static_cast<size_t>(size.x) * static_cast<size_t>(size.y) * 4;
        void* _pixels = malloc(_size);
        memcpy(_pixels, pixels, _size);
        SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom(_pixels,
            size.x, size.y, 32, 8 * size.x, SDL_PIXELFORMAT_RGBA8888);
        this->SetMouseCursor(surface, clickspot);
    }

    void RenderWindow::SetMouseCursor(const Uint32* pixels, Vector2u size, Vector2u clickspot)
    {
        size_t _size = static_cast<size_t>(size.x) * static_cast<size_t>(size.y) * 4;
        void* _pixels = malloc(_size);
        memcpy(_pixels, pixels, _size);
        SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom(_pixels,
            size.x, size.y, 32, 8 * size.x, SDL_PIXELFORMAT_RGBA32);
        this->SetMouseCursor(surface, clickspot);
    }
}