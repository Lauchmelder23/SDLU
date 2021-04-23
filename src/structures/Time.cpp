#include "structures/Time.hpp"
#include "..\..\include\structures\Time.hpp"

SDLU_BEGIN

Time::Time() :
	microseconds(0)
{
}

float Time::AsSeconds() const
{
	return AsValue<float>();
}

Int32 Time::AsMilliseconds() const
{
	return AsValue<Int32, std::milli>();
}

Int64 Time::AsMicroseconds() const
{
	return AsValue<Int64, std::micro>();
}

std::chrono::seconds Time::AsChronoSeconds() const
{
	return AsChrono<std::chrono::seconds>();
}

std::chrono::milliseconds Time::AsChronoMilliseconds() const
{
	return AsChrono<std::chrono::milliseconds>();
}

std::chrono::microseconds Time::AsChronoMicroseconds() const
{
	return AsChrono<std::chrono::microseconds>();
}

Time Seconds(float seconds)
{
	Time newTime;
	newTime.microseconds = std::chrono::duration_cast<std::chrono::duration<Int64, std::micro>>(std::chrono::duration<float>(seconds));
	return newTime;
}

Time Milliseconds(Int32 milliseconds)
{
	Time newTime;
	newTime.microseconds = std::chrono::duration_cast<std::chrono::duration<Int64, std::micro>>(std::chrono::duration<Int32, std::milli>(milliseconds));
	return newTime;
}

Time Microseconds(Int64 microseconds)
{
	Time newTime;
	newTime.microseconds = std::chrono::duration<Int64, std::micro>(microseconds);
	return newTime;
}

SDLU_END