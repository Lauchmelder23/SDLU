/**
 * @file Rectangle.hpp
 * @brief The primitive Rectangle shape
 * @author Lauchmelder23
 * @date 23.05.2020
 */
#pragma once

#include "Shape.hpp"

#include <SDL.h>

namespace sdlu
{
    class Rectangle :
        public Shape
    {
    public:
        /**
         * @brief Default constructor
         */
        Rectangle();

        /**
         * @brief Constructor with default parameters
         * 
         * @param[in] position A 2D position vector
         * @param[in] size     A 2D size vector
         */
        Rectangle(const Vector2f& position, const Vector2f& size);

        /**
         * @brief Gets the size of the rectangle
         * 
         * @return A 2D vector with the size information
         */
        Vector2f GetSize();

        /**
         * @brief Sets a new size for the rectangle
         * 
         * @param[in] size A 2D vector with the size information
         */
        void SetSize(const Vector2f& size);

        /**
         * @brief Sets a new size for the rectangle
         *
         * @param[in] x The new size in x direction
         * @param[in] y The new size in y direction
         */
        void SetSize(float x, float y);

        /**
         * @brief Draws the Rectangle to the target
         *
         * @param[in] target The RenderTarget to draw to
         */
        virtual void Draw(SDL_Renderer* const target) const override;

    private:
        Vector2f size; ///< Size of the rectangle
    };
}