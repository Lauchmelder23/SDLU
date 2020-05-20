#include <SDLU.hpp>
#pragma once
#include "SDLU.hpp"
#include <iostream>

class MyWindow :
    public sdlu::RenderWindow
{
public:
    MyWindow(Uint32 width, Uint32 height, const char* title) :
        RenderWindow(sdlu::Vector2u(width, height), title, 
            SDL_WINDOW_RESIZABLE)
    {
        // Empty
    }
};

void sdlu::Window::OnCreate()
{
    std::cout << "Window was Created!" << std::endl;
}

bool sdlu::Window::OnResize()
{
    std::cout << "Window was Resized!" << std::endl;
    return true;
}

void sdlu::Window::OnClose()
{
    std::cout << "Window was Closed!" << std::endl;
}