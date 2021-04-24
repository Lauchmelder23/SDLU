/**
 * @file Mouse.hpp
 * @brief A static class to provide easy handling of the mouse
 * @author Lauchmelder23
 * @date 19.05.2020
 */
#pragma once
#include "structures/Vector2.hpp"
#include "graphics/RenderWindow.hpp"

SDLU_BEGIN
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
    enum class Button {
        Left = 1,
        Middle = 2,
        Right = 3,
        XButton1 = 4,
        XButton2 = 5
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

    /**
        * @brief Gets the absolute position of the mouse
        *
        * @return Current mouse position relative to screen
        */
    static Vector2i GetPosition();

    /**
        * @brief Gets current relative position of the mouse
        *
        * @param[in] relativeTo The window the mouse position should be relative to
        * @return The position of the mouse relative to the top left of the passed window object
        */
    static Vector2i GetPosition(const RenderWindow& relativeTo);

    /**
        * @brief Sets the absolute position of the mouse
        *
        * @param[in] position A 2D vector of the new position
        */
    static void SetPosition(const Vector2i& position);

    /**
        * @brief Sets current relative position of the mouse
        *
        * @param[in] position A 2D vector of the new position
        * @param[in] relativeTo The window the mouse position should be relative to
        */
    static void SetPosition(const Vector2i& position, const RenderWindow& relativeTo);
};
SDLU_END