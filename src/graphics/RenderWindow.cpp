#include "graphics/RenderWindow.hpp"

#include <cstring>
#include <Util.hpp>

SDLU_BEGIN
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

void RenderWindow::OnCreate()
{
}

bool RenderWindow::OnResize()
{
    return false;
}

void RenderWindow::OnClose()
{
}
SDLU_END