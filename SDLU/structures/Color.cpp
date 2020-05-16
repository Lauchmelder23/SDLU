#include "Color.hpp"

namespace sdlu
{
    const Color Color::Black = Color(0, 0, 0);
    const Color Color::Red = Color(255, 0, 0);
    const Color Color::Green = Color(0, 255, 0);
    const Color Color::Blue = Color(0, 0, 255);
    const Color Color::Yellow = Color(255, 255, 0);
    const Color Color::Magenta = Color(255, 0, 255);
    const Color Color::Cyan = Color(0, 255, 255);
    const Color Color::White = Color(255, 255, 255);

    const Color Color::Transparent = Color(0, 0, 0, 0);

    Color::Color() :
        r(0), g(0), b(0), a(0)
    {
        // Empty
    }

    Color::Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) :
        r(r), g(g), b(b), a(a)
    {
        // Empty
    }

    Color::Color(Uint32 color) : 
        r((color & 0xFF000000) >> 24),
        g((color & 0x00FF0000) >> 16),
        b((color & 0x0000FF00) >> 8),
        a((color & 0x000000FF))
    {
        // Empty
    }

    Uint32 Color::ToInt()
    {
        Uint32 color = 0;
        color |= r << 24;
        color |= g << 16;
        color |= b << 8;
        color |= a;
        return color;
    }
}