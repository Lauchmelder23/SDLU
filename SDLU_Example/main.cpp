#include "header.hpp"

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO);

    MyWindow window(800, 800, "Test");
    SDL_SetWindowTitle(window.GetWindow(), "New Title");

    SDL_Event event;
    float t = 0.f;
    while (window.IsOpen())
    {
        while (window.PollEvent(&event))
        {
            switch (event.window.event)
            {
            case SDL_WINDOWEVENT_CLOSE:
                window.Close();
                break;

            case SDL_WINDOWEVENT_RESIZED:
                std::cout << "If you see this, something isn't working." << std::endl;
                break;
            }
        }

        window.Clear(sdlu::Color::FromHSV(floor(t), 100, 100));

        window.Display();
        t += 0.01;
    }

    SDL_Quit();

    return 0;
}