#pragma once
#include <iostream>
#include <SDLU.hpp>

class MyWindow :
    public sdlu::RenderWindow
{
public:
    MyWindow(Uint32 width, Uint32 height, const char* title) :
        RenderWindow(sdlu::Vector2u(width, height), title, 
            32)
    {
        // Empty
    }

private:
    virtual void OnCreate()
    {
        std::cout << "MyWindow created!" << std::endl;
    }

    virtual bool OnResize()
    {
        std::cout << "MyWindow resized!" << std::endl;
        return true;
    }

    virtual void OnClose()
    {
        std::cout << "MyWindow closed!" << std::endl;
    }
};