/**
 * @file RenderWindow.hpp
 * @brief A wrapper around SDL_Window and SDL_Renderer
 * @author Lauchmelder23
 * @date 16.05.2020
 */
#pragma once
#include <string>
#include <SDL.h>

#include "../structures/Vector2.hpp"

namespace sdlu
{
    class RenderWindow
    {
    public:
        /**
         * @brief Default Constructor. No window or renderer is created.
         */
        RenderWindow();

        /**
         * @brief Creates a window and renderer with the given parameters
         *
         * @param dimension A vector containing the width and height
         * @param title     The title of the create window
         */
        RenderWindow(Vector2u dimension, const std::string& title, 
            Uint32 windowFlags, Uint32 rendererFlags);

        RenderWindow(const RenderWindow& other) = delete;
        RenderWindow(const RenderWindow&& other) = delete;

        /**
         * @brief Creates the window and renderer.
         *
         * This function creates the SDL_Window and SDL_Renderer objects. If
         * they were already created the function does nothing and returns.
         * If it fails to create either, an ObjectCreationException is thrown.
         *
         * @param dimension A vector containing the width and height
         * @param title     The title of the create window
         */
        void Create(Vector2u dimension, const std::string& title, 
            Uint32 windowFlags, Uint32 rendererFlags);

    private:
        SDL_Window* m_pWindow;
        SDL_Renderer* m_pRenderer;
    };
}