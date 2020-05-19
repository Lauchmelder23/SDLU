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
}