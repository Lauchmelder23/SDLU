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
    /**
     * A class that combines the SDL_Window and SDL_Renderer and
     * behaves similar to the sf::RenderWindow from SFML. It provides
     * utility and wrappers for common operations on those objects.
     */
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
         * @param[in] dimension A vector containing the width and height
         * @param[in] title     The title of the create window
         */
        RenderWindow(Vector2u dimension, const std::string& title, 
            Uint32 windowFlags, Uint32 rendererFlags);

        RenderWindow(const RenderWindow& other) = delete;
        RenderWindow(const RenderWindow&& other) = delete;

        virtual ~RenderWindow();

        /**
         * @brief Creates the window and renderer.
         *
         * This function creates the SDL_Window and SDL_Renderer objects. If
         * they were already created the function does nothing and returns.
         * If it fails to create either, an ObjectCreationException is thrown.
         *
         * @param[in] dimension A vector containing the width and height
         * @param[in] title     The title of the create window
         */
        void Create(Vector2u dimension, const std::string& title, 
            Uint32 windowFlags, Uint32 rendererFlags);

        /**
         * @brief Destroys the window and renderer.
         */
        void Close();

        /**
         * @brief Wether or not the window object is created
         *
         * @return True if the window is open, False if not
         */
        bool IsOpen();

        /**
         * @brief A non-blocking event polling function
         *
         * @param[out] event An object to write the latest event to
         * @return True if there was an event, False if there wasn't
         */
        bool PollEvent(SDL_Event* event);

        /**
         * @brief A blocking event polling function
         *
         * @param[out] event An object to write the latest event to
         * @return True if an event was polled
         */
        bool WaitEvent(SDL_Event* event);


        /**
         * @brief Returns the current position of the window
         *
         * @return A vector with the current position relative to the top left corner of the display
         */
        Vector2i GetPosition();

        /**
         * @brief Sets a new window position
         *
         * @param[in] position A vector with the new position
         */
        void SetPosition(Vector2i position);

        /**
         * @brief Sets a new window position
         *
         * @param[in] x The new x position
         * @param[in] y The new y position
         */
        void SetPosition(int x, int y);

        
        /**
         * @brief Gets the current window size
         *
         * @return A vector with the windows size
         */
        Vector2u GetSize();

        /**
         * @brief Sets a new window size
         * 
         * @param[in] size A vector with the new size
         */
        void SetSize(Vector2u size);

        /**
         * @brief Sets a new window size
         *
         * @param[in] width  The new width of the window
         * @param[in] height The new height of the window
         */
        void SetSize(unsigned int width, unsigned int height);

    protected:
        SDL_Window* m_pWindow;      ///< A pointer to the window object
        SDL_Renderer* m_pRenderer;  ///< A pointer to the renderer object

    protected:
        /**
         * @brief This function is called after Create() finishes
         */
        virtual void OnCreate();

        /**
         * @brief This function is called after a SDL_WINDOWEVENT_RESIZED is polled.
         *        (PollEvent() must be called for this to work)
         *
         * @return True if the resize event should be popped from the event queue before
                   returning the polled event to the user
         */
        virtual bool OnResize();

        /**
         * @brief This function is called after Close() finishes.
         */
        virtual void OnClose();
    };
}