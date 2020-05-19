/**
 * @file Mouse.hpp
 * @brief A static class to provide easy handling of the mouse
 * @author Lauchmelder23
 * @date 19.05.2020
 */
#pragma once
#include <SDL_mouse.h>
#include <structures/Vector2.hpp>

namespace sdlu
{
    /**
     * @brief A static class that contains/handles data about
     *        mouse position and button states
     */
    class Mouse
    {
    public:
        /**
         * @brief Mouse buttons
         */
        enum Button {
            Left = SDL_BUTTON_LEFT,
            Right = SDL_BUTTON_RIGHT,
            Middle = SDL_BUTTON_MIDDLE,
            XButton1 = SDL_BUTTON_X1,
            XButton2 = SDL_BUTTON_X2
        };
        
        /**
         * @brief Returns the current mouse button state
         *
         * @return A 32-bit mask of the current button state
         */
        static Uint32 GetButtonState();

        /**
         * @brief Checks if a specific button is pressed
         *
         * @param[in] button The button to check
         * @return True if the button is pressed
         */
        static bool IsButtonDown(Button button);
    };
}