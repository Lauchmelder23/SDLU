#include <graphics/drawable/shapes/Rectangle.hpp>
#include <graphics/RenderTarget.hpp>

#include <SDL.h>

namespace sdlu
{
    Rectangle::Rectangle() :
        Shape()
    {
    }

    Rectangle::Rectangle(const Vector2f& position, const Vector2f& size) :
        Shape()
    {
        this->position = position;
        this->size = size;
    }

    Vector2f Rectangle::GetSize()
    {
        return this->size;
    }

    void Rectangle::SetSize(const Vector2f& size)
    {
        this->size = size;
    }

    void Rectangle::SetSize(float x, float y)
    {
        this->size = Vector2f(x, y);
    }

    void Rectangle::Draw(SDL_Renderer* const renderer) const
    {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_Rect rect;
        rect.x = position.x;
        rect.y = position.y;
        rect.w = size.x;
        rect.h = size.y;
        SDL_RenderFillRect(renderer, &rect);
    }
}