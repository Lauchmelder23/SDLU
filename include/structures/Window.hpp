/**
 * @file Window.hpp
 * @brief Contains window related objects
 * @author Lauchmelder23
 * @date 20.05.20
 */
#pragma once
#include <string>
#include <chrono>

#include "Util.hpp"
#include "structures/Vector2.hpp"

struct SDL_Window;
union SDL_Event;
struct SDL_Surface;
struct SDL_Cursor;

SDLU_BEGIN
class Cursor;

/**
    * @brief Stores information about a window. You probably want RenderWindow.
    */
class Window
{
public:
    enum Flags {
        Fullscreen          = ((Uint32)1 << 0),
        OpenGL              = ((Uint32)1 << 1),
        Shown               = ((Uint32)1 << 2),
        Hidden              = ((Uint32)1 << 3),
        Borderless          = ((Uint32)1 << 4),
        Resizable           = ((Uint32)1 << 5),
        Minimized           = ((Uint32)1 << 6),
        Maximized           = ((Uint32)1 << 7),
        InputGrabbed        = ((Uint32)1 << 8),
        InputFocus          = ((Uint32)1 << 9),
        MouseFocus          = ((Uint32)1 << 10),
        Foregin             = ((Uint32)1 << 11),
        FullscreenDesktop   = (Fullscreen | ((Uint32)1 << 12)),
    };
public:
    /**
        * @brief Default Constructor. No window is created.
        */
    Window();

    /**
        * @brief Creates a window with the given parameters
        *
        * @param[in] dimension A vector containing the width and height
        * @param[in] title     The title of the create window
        */
    Window(Vector2u dimension, const std::string& title,
        Uint32 windowFlags);

    Window(const Window& other) = delete;
    Window(Window&& other) = delete;

    virtual ~Window();

    /**
        * @brief Creates the window.
        *
        * This function creates the SDL_Window object. If
        * they were already created the function does nothing and returns.
        * If it fails to create either, an ObjectCreationException is thrown.
        *
        * @param[in] dimension A vector containing the width and height
        * @param[in] title     The title of the create window
        */
    void Create(Vector2u dimension, const std::string& title,
        Uint32 windowFlags);

    /**
        * @brief Destroys the window.
        */
    void Close();

    /**
        * @brief Wether or not the window object is created
        *
        * @return True if the window is open, False if not
        */
    bool IsOpen() const;

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
    Vector2i GetPosition() const;

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
    Vector2u GetSize() const;

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


    /**
        * @brief Gets the current window title
        *
        * @return The title of the widnow
        */
    std::string GetTitle() const;

    /**
        * @brief Sets a new window title
        *
        * @param[in] title The new window title
        */
    void SetTitle(std::string title);

    /**
        * @brief Returns a constant pointer to the SDL_Window
        *
        * @return A constant pointer to SDL_Window
        */
    SDL_Window* const GetWindow() const;

    /**
        * @brief Set the windows visibility
        *
        * @param[in] visible The new visibility setting
        */
    void SetVisible(bool visible);

    /**
        * @brief (De)activates VSync !globally!
        *
        * @param[in] vsync Wether to enable or disable vsync
        */
    void SetVsync(bool vsync);

    /**
        * @brief Hides/Shows the mouse cursor inside the windos
        *
        * @param[in] visible The new visibility of the cursor
        */
    void SetMouseCursorVisible(bool visible);

    /**
        * @brief Traps the mouse cursor inside the window
        *
        * @param[in] grabbed Wether to (un)trap the cursor
        */
    void SetMouseCursorGrabbed(bool grabbed);

    /**
        * @brief Sets the window icon to an array of RGBA values
        *
        * @param[in] width  Width of the icon (in px)
        * @param[in] height Height of the icon (in px)
        * @param[in] pixels Array of color data (RGBA as seperate 8-Bit integer values)
        */
    void SetIcon(Uint32 width, Uint32 height, const Uint8* pixels);

    /**
        * @brief Sets the window icon to an array of RGBA values
        *
        * @param[in] width  Width of the icon (in px)
        * @param[in] height Height of the icon (in px)
        * @param[in] pixels Array of color data (RGBA as one 32-Bit integer value)
        */
    void SetIcon(Uint32 width, Uint32 height, const Uint32* pixels);

    /**
        * @brief Sets the window icon to a SDL_Surface
        *
        * @param[in] icon A SDL_Surface* holding the icon data
        */
    void SetIcon(SDL_Surface* icon);

    /**
        * @brief Changes the mouse cursor
        *
        * @param[in] cursor A pointer to a SDL_Cursor containing cursor data
        */
    void SetMouseCursor(SDL_Cursor* cursor);

    /**
        * @brief Changes the mouse cursor
        *
        * @param[in] cursor   The cursor object holding cursor data
        */
    void SetMouseCursor(const Cursor& cursor);

protected:
    SDL_Window* window;

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
SDLU_END