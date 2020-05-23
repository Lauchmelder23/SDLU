#include "Transformable.hpp"

namespace sdlu
{
    Transformable::Transformable() :
        m_oPosition(0, 0), m_oOrigin(0, 0),
        m_oScale(1.f, 1.f), m_fRotation(0.f)
    {
        // Empty
    }

    Transformable::~Transformable()
    {
        // Empty
    }

    Vector2f Transformable::GetPosition()
    {
        return m_oPosition;
    }

    void Transformable::SetPosition(const Vector2f& position)
    {
        m_oPosition = position;
    }

    void Transformable::SetPosition(float x, float y)
    {
        m_oPosition = Vector2f(x, y);
    }

    void Transformable::Move(const Vector2f& position)
    {
        m_oPosition += position;
    }

    void Transformable::Move(float x, float y)
    {
        m_oPosition += Vector2f(x, y);
    }
    Vector2f Transformable::GetOrigin()
    {
        return m_oOrigin;
    }

    void Transformable::SetOrigin(const Vector2f& origin)
    {
        m_oOrigin = origin;
    }

    void Transformable::SetOrigin(float x, float y)
    {
        m_oOrigin = Vector2f(x, y);
    }

    Vector2f Transformable::GetScale()
    {
        return m_oScale;
    }

    void Transformable::SetScale(const Vector2f& scale)
    {
        m_oScale = scale;
    }

    void Transformable::SetScale(float x, float y)
    {
        m_oScale = Vector2f(x, y);
    }

    void Transformable::Scale(const Vector2f& scale)
    {
        m_oScale += scale;
    }

    void Transformable::Scale(float x, float y)
    {
        m_oScale += Vector2f(x, y);
    }

    float Transformable::GetRotation()
    {
        return m_fRotation;
    }

    void Transformable::SetRotation(float angle)
    {
        m_fRotation = angle;
    }

    void Transformable::Rotate(float angle)
    {
        m_fRotation += angle;
    }
}