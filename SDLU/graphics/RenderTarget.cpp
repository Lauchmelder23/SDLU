#include "RenderTarget.hpp"

#include <Util.hpp>
#include <exceptions/Exceptions.hpp>

namespace sdlu
{
    Uint32 RenderTarget::m_uRenderers = -1;

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
        renderer = SDL_CreateRenderer(target, m_uRenderers, SDL_RENDERER_ACCELERATED);
        
        THROW_IF(IS_NULLPTR(renderer),
            sdlu::ObjectCreationException("Failed to create SDL_Renderer* from SDL_Window*: "
                + std::string(SDL_GetError())));
        m_uRenderers++;

        m_oTimeSinceLastDisplay = std::chrono::steady_clock::now();
    }

    RenderTarget::RenderTarget(SDL_Surface* target) : 
        renderer(nullptr), m_oFramerate(0)
    {
        m_oFramerate = 0;

        RETURN_IF_NOT_NULLPTR(renderer);
        renderer = SDL_CreateSoftwareRenderer(target);

        THROW_IF(IS_NULLPTR(renderer),
            sdlu::ObjectCreationException("Failed to create SDL_Renderer* from SDL_Surface*: "
                + std::string(SDL_GetError())));
        m_uRenderers++;

        m_oTimeSinceLastDisplay = std::chrono::steady_clock::now();
    }
}