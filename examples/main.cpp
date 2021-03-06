#include "header.hpp"

#include <SDL_events.h>

#include <math.h>
#include <cmath>

int main(int argc, char** argv)
{
    sdlu::Initialize();

    sdlu::Time test = sdlu::Microseconds(420);
    std::cout << test.AsSeconds() << std::endl;

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

    sdlu::Clock timer;
    Uint64 diff = 1;

    MyWindow window(800, 800, "Test");
    window.SetTitle("New Title");

    window.SetIcon(64, 64, icon_data);
    window.SetMouseCursor(sdlu::Cursor::Type::Crosshair);
    window.SetMaxFramerate(144);

    SDL_Event event;

    sdlu::Rectangle rect(sdlu::Vec2f(100, 100), sdlu::Vec2f(300, 200));
    rect.SetColor(sdlu::Color::Blue);

    std::string title = "";
    while (window.IsOpen())
    {
        title = "";
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

        sdlu::Vector2i mousePos = sdlu::Mouse::GetPosition(window) - sdlu::Vector2i(400, 400);
        // TODO: Check HSV color conversion, the SV values seem to be ignored
        window.Clear(sdlu::Color::FromHSV(std::atan2(mousePos.y, mousePos.x) / PI * 180 + 180, 
            100, 100));

        window.Draw(rect);

        window.Display();

        diff = timer.Restart().AsMicroseconds();
        title += (std::to_string(1000000 / diff) + " FPS | Mouse: ");
        title += (sdlu::Mouse::IsButtonDown(sdlu::Mouse::Button::Left)) ? "L " : "l ";
        title += (sdlu::Mouse::IsButtonDown(sdlu::Mouse::Button::Middle)) ? "M " : "m ";
        title += (sdlu::Mouse::IsButtonDown(sdlu::Mouse::Button::Right)) ? "R " : "r ";
        title += (sdlu::Mouse::IsButtonDown(sdlu::Mouse::Button::XButton1)) ? "X1 " : "x1 ";
        title += (sdlu::Mouse::IsButtonDown(sdlu::Mouse::Button::XButton2)) ? "X2" : "x2";

        window.SetTitle(title);
    }

    sdlu::Quit();
    return 0;
}
