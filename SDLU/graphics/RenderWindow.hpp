/**
 * @file RenderWindow.hpp
 * @brief A wrapper around SDL_Window and SDL_Renderer
 * @author Lauchmelder23
 * @date 16.05.2020
 */
#pragma once
#include <string>
#include <chrono>

#include <SDL.h>

#include <structures/Vector2.hpp>
#include <structures/Color.hpp>
#include <structures/Window.hpp>
#include <graphics/RenderTarget.hpp>

namespace sdlu
{
    // TODO: Probably break up into sdlu::Window and sdlu::Renderer
    // to avoid passing around the Renderer when only the Window is
    // needed. (See Mouse::GetPosition for example)

    /**
     * @brief A class that handles window related functionality
     *
     * A class that combines the SDL_Window and SDL_Renderer and
     * behaves similar to the sf::RenderWindow from SFML. It provides
     * utility and wrappers for common operations on those objects.
     */
    class RenderWindow : public Window, public RenderTarget
    {
    public:
        /**
         * @brief Default Constructor. No window or renderer is created.
         */
        RenderWindow();

        /**
         * @brief Creates a window and renderer with the given parameters
         *
         * @param[in] dimension A vector containing the width and height
         * @param[in] title     The title of the create window
         */
        RenderWindow(Vector2u dimension, const std::string& title, 
            Uint32 windowFlags);

        RenderWindow(const RenderWindow& other) = delete;
        RenderWindow(const RenderWindow&& other) = delete;

        virtual ~RenderWindow();
    };
}