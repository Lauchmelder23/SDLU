/**
 * @file Drawable.hpp
 * @brief The base class of everything renderable by RenderTarget
 * @author Lauchmelder23
 * @date 20.05.2020
 */
#pragma once

#include <graphics/RenderTarget.hpp>

namespace sdlu
{
    /** 
     * @brief Everything that can be rendered derives from this class.
     */
    class Drawable
    {
    public:
        Drawable() = delete;
        Drawable(const Drawable& other) = delete;
        Drawable(Drawable&& other) = delete;
        Drawable& operator=(const Drawable& other) = delete;

        friend class RenderTarget;

    protected:
        virtual void Draw(RenderTarget& target) const = 0;
    };
}