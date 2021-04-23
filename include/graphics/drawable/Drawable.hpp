/**
 * @file Drawable.hpp
 * @brief The base class of everything renderable by RenderTarget
 * @author Lauchmelder23
 * @date 20.05.2020
 */
#pragma once

#include "Util.hpp"

struct SDL_Renderer;

SDLU_BEGIN
/** 
    * @brief Everything that can be rendered derives from this class.
    */
class Drawable
{
public:
    Drawable(const Drawable& other) = delete;
    Drawable(Drawable&& other) = delete;
    Drawable& operator=(const Drawable& other) = delete;

    friend class RenderTarget;

protected:
    Drawable() { }
    virtual void Draw(SDL_Renderer* const target) const = 0;
};
SDLU_END