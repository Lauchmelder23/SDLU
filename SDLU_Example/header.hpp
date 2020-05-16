#pragma once
#include "SDLU.hpp"
#include <iostream>

class MyWindow :
    public sdlu::RenderWindow
{
public:
    MyWindow(Uint32 width, Uint32 height, const char* title) :
        RenderWindow(sdlu::Vector2u(width, height), title, NULL, NULL)
    {
        // Empty
    }
};

void sdlu::RenderWindow::OnCreate()
{
    std::cout << "Window was Created!" << std::endl;
}

bool sdlu::RenderWindow::OnResize()
{
    std::cout << "Window was Resized!" << std::endl;
    return false;
}

void sdlu::RenderWindow::OnClose()
{
    std::cout << "Window was Closed!" << std::endl;
}