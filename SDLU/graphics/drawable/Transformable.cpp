#include "Transformable.hpp"

namespace sdlu
{
    Transformable::Transformable() :
        position(0, 0), origin(0, 0),
        scale(1.f, 1.f), rotation(0.f)
    {
        // Empty
    }

    Transformable::~Transformable()
    {
        // Empty
    }

    Vector2f Transformable::GetPosition()
    {
        return position;
    }

    void Transformable::SetPosition(const Vector2f& position)
    {
        this->position = position;
    }

    void Transformable::SetPosition(float x, float y)
    {
        position = Vector2f(x, y);
    }

    void Transformable::Move(const Vector2f& position)
    {
        this->position += position;
    }

    void Transformable::Move(float x, float y)
    {
        position += Vector2f(x, y);
    }
    Vector2f Transformable::GetOrigin()
    {
        return origin;
    }

    void Transformable::SetOrigin(const Vector2f& origin)
    {
        this->origin = origin;
    }

    void Transformable::SetOrigin(float x, float y)
    {
        origin = Vector2f(x, y);
    }

    Vector2f Transformable::GetScale()
    {
        return scale;
    }

    void Transformable::SetScale(const Vector2f& scale)
    {
        this->scale = scale;
    }

    void Transformable::SetScale(float x, float y)
    {
        scale = Vector2f(x, y);
    }

    void Transformable::Scale(const Vector2f& scale)
    {
        this->scale += scale;
    }

    void Transformable::Scale(float x, float y)
    {
        scale += Vector2f(x, y);
    }

    float Transformable::GetRotation()
    {
        return rotation;
    }

    void Transformable::SetRotation(float angle)
    {
        rotation = angle;
    }

    void Transformable::Rotate(float angle)
    {
        rotation += angle;
    }
}