#include "header.hpp"

int main(int argc, char** argv)
{
    sdlu::Vector2f vecA(.4f, -2.3f);
    sdlu::Vector2f vecB(-8.9f, 0.003f);
    sdlu::Vector2f vec = vecA + vecB;

    std::cout << "Vector2f: " << vec.x << ", " << vec.y << std::endl;

    vec *= 1.8f;
    std::cout << "Vector2f: " << vec.x << ", " << vec.y << std::endl;

    MyWindow window(800, 800, "Test");

    SDL_Event event;
    while (window.WaitEvent(&event))
    {
        std::cout << event.type << std::endl;
    }

    return 0;
}