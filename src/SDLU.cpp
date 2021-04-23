#include "SDLU.hpp"

#include <SDL.h>
#include "Util.hpp"

SDLU_BEGIN

int Initialize() {
	return SDL_Init(SDL_INIT_EVERYTHING);
}

void Quit() {
	SDL_Quit();
}

SDL_CommonEvent c;

SDLU_END