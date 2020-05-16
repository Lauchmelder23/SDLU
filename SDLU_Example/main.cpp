#include "header.hpp"

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO);

    MyWindow window(800, 800, "Test");
    SDL_SetWindowTitle(window.GetWindow(), "New Title");
    window.SetMouseCursorGrabbed(true);

    SDL_Event event;
    while (window.IsOpen())
    {
        while (window.PollEvent(&event))
        {
            switch (event.window.event)
            {
            case SDL_WINDOWEVENT_CLOSE:
                window.Close();
                break;
            }
        }

        window.Clear(sdlu::Color::Magenta);

        window.Display();
    }

    SDL_Quit();

    return 0;
}