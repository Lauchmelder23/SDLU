#include "header.hpp"

int main(int argc, char** argv)
{
    SDL_Init(SDL_INIT_VIDEO);

    Uint32* icon_data = new Uint32[64 * 64];
    for (int y = 0; y < 64; y++)
    {
        for (int x = 0; x < 64; x++)
        {
            icon_data[64 * y + x] = 0x004400FF;
            icon_data[64 * y + x] |= (((Uint32)((y / 64.f) * 255) << 24));
            icon_data[64 * y + x] |= (((Uint32)((x / 64.f) * 255) << 8));
        }
    }

    MyWindow window(800, 800, "Test");
    SDL_SetWindowTitle(window.GetWindow(), "New Title");

    window.SetIcon(64, 64, icon_data);

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