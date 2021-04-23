#pragma once 

#include "Vector2.hpp"
#include "Util.hpp"

struct SDL_Cursor;
struct SDL_Surface;

SDLU_BEGIN

class Cursor
{
public:
	enum class Type {
		Arrow, IBeam, Wait, Crosshair, WaitArrow,
		SizeNWSE, SizeNESW, SizeWE, SizeNS, SizeAll,
		No, Hand
	};

	friend class Window;

public:
	Cursor();
	Cursor(Type type);
	Cursor(const Cursor& other) = delete;
	Cursor(Cursor&& other) noexcept;

	~Cursor();

	bool LoadFromPixels(const Uint8* pixels, Vector2u size, Vector2u hotspot);
	bool LoadFromSurface(SDL_Surface* surface, Vector2u hotspot);
	bool LoadFromSystem(Type type);

private:
	SDL_Cursor* cursor;
};

SDLU_END