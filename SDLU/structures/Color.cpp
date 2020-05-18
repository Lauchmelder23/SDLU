#include "Color.hpp"

#include <math.h>
#include <cmath>

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

    Color Color::FromHSV(Uint16 h, Uint8 s, Uint8 v)
    {
        // Normalize parameters
        // H : [0, 360)
        // S : [0, 1]
        // V : [0, 1]
        h -= std::floor(h / 360) * 360;
        s = (s > 1) ? 1 : s;
        v = (v > 1) ? 1 : v;

        // Convert to RGBA
        Uint16 H = std::floor(h / 60.f);
        float f = (h / 60.f) - H;

        Uint8 p = static_cast<Uint8>((v * (1 - s)) * 255);
        Uint8 q = static_cast<Uint8>((v * (1 - s * f)) * 255);
        Uint8 t = static_cast<Uint8>((v * (1 - s * (1 - f))) * 255);
        v *= 255;

        Color output;
        switch (H)
        {
        case 0:
        case 6:
            output = Color(v, t, p);
            break;
        case 1:
            output = Color(q, v, p);
            break;
        case 2:
            output = Color(p, v, t);
            break;
        case 3:
            output = Color(p, q, v);
            break;
        case 4:
            output = Color(t, p, v);
            break;
        case 5:
            output = Color(v, p, q);
            break;
        default:
            break;
        }

        return output;
    }

    Color operator+(const Color& left, const Color& right)
    {
        return Color((UINT8_MAX - left.r) < right.r ? 255 : left.r + right.r,
            (UINT8_MAX - left.g) < right.g ? 255 : left.g + right.g,
            (UINT8_MAX - left.b) < right.b ? 255 : left.b + right.b,
            (UINT8_MAX - left.a) < right.a ? 255 : left.a + right.a);
    }

    Color operator-(const Color& left, const Color& right)
    {
        return Color(left.r < right.r ? 0 : left.r - right.r,
            left.g < right.g ? 0 : left.g - right.g,
            left.b < right.b ? 0 : left.b - right.b,
            left.a < right.a ? 0 : left.a - right.a);
    }

    Color operator*(const Color& left, const Color& right)
    {
        return Color((UINT8_MAX / left.r) < right.r ? 255 : left.r * right.r,
            (UINT8_MAX / left.g) < right.g ? 255 : left.g * right.g,
            (UINT8_MAX / left.b) < right.b ? 255 : left.b * right.b,
            (UINT8_MAX / left.a) < right.a ? 255 : left.a * right.a);
    }

    Color operator/(const Color& left, const Color& right)
    {
        return Color(left.r / right.r,
            left.g / right.g,
            left.b / right.b,
            left.a / right.a);
    }

    Color& operator+=(Color& left, const Color& right)
    {
        left = left + right;
        return left;
    }

    Color& operator-=(Color& left, const Color& right)
    {
        left = left - right;
        return left;
    }

    Color& operator*=(Color& left, const Color& right)
    {
        left = left * right;
        return left;
    }

    Color& operator/=(Color& left, const Color& right)
    {
        left = left / right;
        return left;
    }

    bool operator==(const Color& left, const Color& right)
    {
        return ((left.r == right.r) && (left.g == right.g) && (left.b == right.b) && (left.a == right.a));
    }

    bool operator!=(const Color& left, const Color& right)
    {
        return !(left == right);
    }
}