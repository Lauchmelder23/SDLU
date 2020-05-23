#include "Shape.hpp"

namespace sdlu
{
    Shape::~Shape()
    {
    }

    void Shape::SetColor(const Color& color)
    {
        this->color = color;
    }

    Color Shape::GetColor()
    {
        return color;
    }

    Shape::Shape() :
        Drawable(), Transformable()
    {
    }
}