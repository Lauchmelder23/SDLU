#include "structures/Clock.hpp"

SDLU_BEGIN

Clock::Clock()
{
}

Time Clock::GetElapsedTime()
{
	return (Time::Now() - lastTime);
}

Time Clock::Restart()
{
	Time elapsedTime = GetElapsedTime();
	lastTime = Time::Now();
	return elapsedTime;
}

SDLU_END