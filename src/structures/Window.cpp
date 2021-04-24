#include "structures/Window.hpp"

#include <stdexcept>

#include <SDL.h>
#include <cstring>

#include "structures/Cursor.hpp"

SDLU_BEGIN
Window::Window() :
    window(nullptr)
{
    // Empty
}

Window::Window(Vector2u dimension, const std::string& title, Uint32 windowFlags) :
    Window()
{
    Create(dimension, title, windowFlags);
}

Window::~Window()
{
    Close();
}

void Window::Create(Vector2u dimension, const std::string& title, Uint32 windowFlags)
{
    // Don't create a window when it already exists
    RETURN_IF_NOT_NULLPTR(window);

    window = SDL_CreateWindow(title.c_str(),
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        dimension.x, dimension.y,
        windowFlags);

    THROW_IF(IS_NULLPTR(window),
        std::runtime_error("Failed to create SDL_Window. \nSDL_GetError(): " + std::string(SDL_GetError())));

    OnCreate();
}

void Window::Close()
{
    // Don't destroy a window that doesn't exist
    RETURN_IF_NULLPTR(window);

    SDL_DestroyWindow(window);
    window = nullptr;

    OnClose();
}

bool Window::IsOpen() const
{
    RETURN_IF_NULLPTR(window, false);
    return (!SDL_GetWindowID(window) ? false : true);
}

bool Window::PollEvent(SDL_Event* event)
{
    RETURN_IF_NULLPTR(window, false);
    // Handle events before the user in case a derived
    // class decides to block the event.
    while (SDL_PollEvent(event))
    {
        switch (event->window.event)
        {
        case SDL_WINDOWEVENT_RESIZED: if (!OnResize()) return true; break;
        default: return true;
        }
    }

    event = NULL;
    return false;
}

bool Window::WaitEvent(SDL_Event* event)
{
    while (!PollEvent(event)) continue;
    return true;
}

Vector2i Window::GetPosition() const
{
    RETURN_IF_NULLPTR(window, Vector2i());

    int x = 0, y = 0;
    SDL_GetWindowPosition(window, &x, &y);
    return Vector2i(x, y);
}

void Window::SetPosition(Vector2i position)
{
    RETURN_IF_NULLPTR(window);

    SDL_SetWindowPosition(window, position.x, position.y);
}

void Window::SetPosition(int x, int y)
{
    RETURN_IF_NULLPTR(window);

    SDL_SetWindowPosition(window, x, y);
}

Vector2u Window::GetSize() const
{
    RETURN_IF_NULLPTR(window, Vector2u());

    int x = 0, y = 0;
    SDL_GetWindowSize(window, &x, &y);
    return Vector2u(x, y);
}

void Window::SetSize(Vector2u size)
{
    RETURN_IF_NULLPTR(window);

    SDL_SetWindowSize(window, size.x, size.y);
}

void Window::SetSize(unsigned int width, unsigned int height)
{
    RETURN_IF_NULLPTR(window);

    SDL_SetWindowSize(window, width, height);
}

std::string Window::GetTitle() const
{
    RETURN_IF_NULLPTR(window, "");

    return SDL_GetWindowTitle(window);
}

void Window::SetTitle(std::string title)
{
    RETURN_IF_NULLPTR(window);

    SDL_SetWindowTitle(window, title.c_str());
}

SDL_Window* const Window::GetWindow() const
{
    return window;
}

void Window::SetVisible(bool visible)
{
    RETURN_IF_NULLPTR(window);
    if (visible)
        SDL_ShowWindow(window);
    else
        SDL_HideWindow(window);
}

void Window::SetVsync(bool vsync)
{
    // SDL actually doesn't allow you to change the VSync
    // flag of a Renderer after it's been created. This
    // Changes it globally for all other windows
    SDL_GL_SetSwapInterval(vsync);
}

void Window::SetMouseCursorVisible(bool visible)
{
    SDL_ShowCursor(visible);
}

void Window::SetMouseCursorGrabbed(bool grabbed)
{
    SDL_SetWindowGrab(window, grabbed ? SDL_TRUE : SDL_FALSE);
}

void Window::SetIcon(Uint32 width, Uint32 height, const Uint8* pixels)
{
    size_t size = static_cast<size_t>(width) * static_cast<size_t>(height) * 4;
    void* _pixels = malloc(size);
    memcpy(_pixels, pixels, size);
    SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom(_pixels,
        width, height, 32, 32 * width,
        SDL_PIXELFORMAT_RGBA8888);

    SDL_SetWindowIcon(window, surface);
}

void Window::SetIcon(Uint32 width, Uint32 height, const Uint32* pixels)
{
    size_t size = static_cast<size_t>(width) * static_cast<size_t>(height) * 4;
    void* _pixels = malloc(size);
    memcpy(_pixels, pixels, size);
    SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom(_pixels,
        width, height, 32, 4 * width,
        SDL_PIXELFORMAT_RGBA8888);

    SDL_SetWindowIcon(window, surface);
}

void Window::SetIcon(SDL_Surface* icon)
{
    SDL_SetWindowIcon(window, icon);
}

void Window::SetMouseCursor(SDL_Cursor* cursor)
{
    SDL_SetCursor(cursor);
}

void Window::SetMouseCursor(const Cursor& cursor)
{
    SDL_SetCursor(cursor.cursor);
}

void Window::OnCreate()
{
}

bool Window::OnResize()
{
    return false;
}

void Window::OnClose()
{
}
SDLU_END
