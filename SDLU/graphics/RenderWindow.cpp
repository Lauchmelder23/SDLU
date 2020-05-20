#include "RenderWindow.hpp"

#include <cstring>

#include <exceptions/Exceptions.hpp>
#include <Util.hpp>

namespace sdlu
{
    RenderWindow::RenderWindow() :
        Window(), RenderTarget(window)
    {
        // Empty
    }

    RenderWindow::RenderWindow(Vector2u dimension, const std::string& title,
        Uint32 windowFlags) :
        Window(dimension, title, windowFlags), RenderTarget(window)
    {
        // Empty
    }

    RenderWindow::~RenderWindow()
    {
        // Empty
    }
}