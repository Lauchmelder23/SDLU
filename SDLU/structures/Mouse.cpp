#include "Mouse.hpp"

#include <SDL_mouse.h>

namespace sdlu
{
    Uint32 Mouse::GetButtonState()
    {
        return SDL_GetMouseState(NULL, NULL);
    }

    bool Mouse::IsButtonDown(Button button)
    {
        return (GetButtonState() & SDL_BUTTON(button));
    }

    Vector2i Mouse::GetPosition()
    {
        int x = 0, y = 0;
        SDL_GetGlobalMouseState(&x, &y);
        return Vector2i(x, y);
    }

    Vector2i Mouse::GetPosition(const RenderWindow& relativeTo)
    {
        return GetPosition() - relativeTo.GetPosition();
    }

    void Mouse::SetPosition(const Vector2i& position)
    {
        SDL_WarpMouseGlobal(position.x, position.y);
    }

    void Mouse::SetPosition(const Vector2i& position, const RenderWindow& relativeTo)
    {
        SDL_WarpMouseInWindow(relativeTo.GetWindow(), position.x, position.y);
    }
}