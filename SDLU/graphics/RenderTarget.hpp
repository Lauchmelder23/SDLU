/**
 * @file RenderTarget
 * @brief Contains rendering related objects
 * @author Lauchmelder23
 * @date 20.05.2020
 */
#pragma once
#include <chrono>

#include <SDL.h>

#include <structures/Color.hpp>
#include <graphics/drawable/Drawable.hpp>

namespace sdlu
{
    /**
     * @brief Acts as a wrapper for SDL_Renderer*. You can't (and shouldn't)
     *        instantiate this, but rather derive from it.
     */ 
    class RenderTarget
    {
    public:
        virtual ~RenderTarget();

        /**
         * @brief Clears the display
         *
         * @param[in] color The color to clear the display with
         */
        void Clear(const Color& color = Color::Black);

        /**
         * @brief Draws a sdlu::Drawable to the SDL_Renderer
         *
         * @param[in] drawable A reference to a derived class of Drawable
         */
        void Draw(const Drawable& drawable);

        /**
         * @brief Display the current state of the renderer to the screen
         */
        void Display();

        /**
         * @brief Sets a maximum framerate on the display function
         *
         * If the maximum framerate is not 0, SDL_Delay() will be called
         * after each Display() to ensure that the time between displays
         * is not shorter than the framerate limit.
         *
         * @param[in] max The new maximum framerate
         */
        void SetMaxFramerate(Uint32 max);

    protected:
        /**
         * @brief Create Renderer and bind it to a window
         * 
         * @param[in] target The SDL_Window to bind to
         */
        RenderTarget(SDL_Window* target);

        /**
         * @brief Create Renderer and bind it to a texture
         *
         * @param[in] target The SDL_Surface to bind to
         */
        RenderTarget(SDL_Surface* target);

    protected:
        SDL_Renderer* renderer; ///< The renderer object

    private:
        Uint32 m_oFramerate; ///< The current maximum framerate of the window (0 = unlimited)

        std::chrono::steady_clock::time_point m_oTimeSinceLastDisplay; ///< The timepoint at which Display() was last called

        static Uint32 m_uRenderers; ///< The number of renderers instantiated so far
    };
}