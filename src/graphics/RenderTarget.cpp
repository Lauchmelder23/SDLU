#include "graphics/RenderTarget.hpp"

#include <stdexcept>

#include <SDL.h>
#include "Util.hpp"

SDLU_BEGIN
RenderTarget::~RenderTarget()
{
    RETURN_IF_NULLPTR(renderer);

    SDL_DestroyRenderer(renderer);
}

void RenderTarget::Clear(const Color& color)
{
    RETURN_IF_NULLPTR(renderer);

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(renderer);
}

void RenderTarget::Draw(const Drawable& drawable)
{
    RETURN_IF_NULLPTR(renderer);

    drawable.Draw(renderer);
}

void RenderTarget::Display()
{
    RETURN_IF_NULLPTR(renderer);

    SDL_RenderPresent(renderer);

    if (m_oFramerate != 0)
    {
        Uint64 diff = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - m_oTimeSinceLastDisplay).count();

        if (diff < 1000 / m_oFramerate)
        {
            SDL_Delay(static_cast<Uint32>(1000 / m_oFramerate - diff));
        }
    }

    m_oTimeSinceLastDisplay = std::chrono::steady_clock::now();
}

void RenderTarget::SetMaxFramerate(Uint32 max)
{
    m_oFramerate = max;
}

RenderTarget::RenderTarget(SDL_Window* target) :
    renderer(nullptr), m_oFramerate(0)
{
    RETURN_IF_NOT_NULLPTR(renderer);
    renderer = SDL_CreateRenderer(target, -1, SDL_RENDERER_ACCELERATED);
        
    THROW_IF(IS_NULLPTR(renderer),
        std::runtime_error("Failed to create SDL_Renderer* from SDL_Window*: " + std::string(SDL_GetError())));

    m_oTimeSinceLastDisplay = std::chrono::steady_clock::now();
}

RenderTarget::RenderTarget(SDL_Surface* target) : 
    renderer(nullptr), m_oFramerate(0)
{
    m_oFramerate = 0;

    RETURN_IF_NOT_NULLPTR(renderer);
    renderer = SDL_CreateSoftwareRenderer(target);

    THROW_IF(IS_NULLPTR(renderer),
        std::runtime_error("Failed to create SDL_Renderer* from SDL_Surface*: " + std::string(SDL_GetError())));

    m_oTimeSinceLastDisplay = std::chrono::steady_clock::now();
}
SDLU_END
