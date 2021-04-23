#include "structures/Cursor.hpp"

#include <SDL2/SDL_mouse.h>

SDLU_BEGIN

Cursor::Cursor() :
	cursor(SDL_CreateSystemCursor(static_cast<SDL_SystemCursor>(Type::Arrow)))
{
	
}

Cursor::Cursor(Type type) :
	cursor(SDL_CreateSystemCursor(static_cast<SDL_SystemCursor>(type)))
{
}

Cursor::Cursor(Cursor&& other) noexcept
{
	this->cursor = other.cursor;
	other.cursor = nullptr;
}

Cursor::~Cursor()
{
	SDL_FreeCursor(cursor);
}

bool Cursor::LoadFromPixels(const Uint8* pixels, Vector2u size, Vector2u hotspot)
{
	SDL_FreeCursor(cursor);
	cursor = SDL_CreateCursor(pixels, nullptr, size.x, size.y, hotspot.x, hotspot.y);

	if (IS_NULLPTR(cursor))
		return false;

	return true;
}

bool Cursor::LoadFromSurface(SDL_Surface* surface, Vector2u hotspot)
{
	SDL_FreeCursor(cursor);
	cursor = SDL_CreateColorCursor(surface, hotspot.x, hotspot.y);

	if (IS_NULLPTR(cursor))
		return false;

	return true;
}

bool Cursor::LoadFromSystem(Type type)
{
	SDL_FreeCursor(cursor);
	cursor = SDL_CreateSystemCursor(static_cast<SDL_SystemCursor>(type));

	if (IS_NULLPTR(cursor))
		return false;

	return true;
}

SDLU_END