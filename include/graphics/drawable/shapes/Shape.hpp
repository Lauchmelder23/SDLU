/**
 * @file Shape.hpp
 * @brief The base class for all native SDLU shapes
 * @author Lauchmelder23
 * @date 23.05.2020
 */
#pragma once

#include "graphics/drawable/Drawable.hpp"
#include "graphics/drawable/Transformable.hpp"
#include "structures/Color.hpp"

SDLU_BEGIN
/**
    * @brief The non-instantiable base class for all SDLU shapes
    */
class Shape :
    public Drawable, public Transformable
{
public:
    /**
        * @brief Deconstructor
        */
    virtual ~Shape();

    /**
        * @brief Sets the color of the shape
        */
    void SetColor(const Color& color);

    /**
        * @brief Gets the color of the shape
        */
    Color GetColor();

protected:
    /**
        * @brief Default constructor
        */
    Shape();

protected:
    Color color;
};
SDLU_END