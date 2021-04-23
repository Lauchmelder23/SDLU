#pragma once

#include "Util.hpp"
#include "Time.hpp"

SDLU_BEGIN

class Clock
{
public:
	Clock();

	Time GetElapsedTime();
	Time Restart();

private:
	Time lastTime;
};

SDLU_END