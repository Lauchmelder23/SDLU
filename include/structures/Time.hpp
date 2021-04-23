#pragma once

#include <chrono>

#include "Util.hpp"

SDLU_BEGIN

class Time {
public:
	Time();

	template<typename Rep = Int64, typename Period = std::ratio<1>> Rep AsValue() const;
	float AsSeconds() const;
	Int32 AsMilliseconds() const;
	Int64 AsMicroseconds() const;

	template<typename Duration = std::chrono::seconds> Duration AsChrono() const;
	std::chrono::seconds AsChronoSeconds() const;
	std::chrono::milliseconds AsChronoMilliseconds() const;
	std::chrono::microseconds AsChronoMicroseconds() const;

	friend Time Seconds(float seconds);
	friend Time Milliseconds(Int32 milliseconds);
	friend Time Microseconds(Int64 microseconds);

private:
	std::chrono::duration<Int64, std::micro> microseconds;
};


template<typename Rep, typename Period>
inline Rep Time::AsValue() const
{
	return std::chrono::duration_cast<std::chrono::duration<Rep, Period>>(microseconds).count();
}

template<typename Duration>
inline Duration Time::AsChrono() const
{
	return std::chrono::duration_cast<Duration>(microseconds);
}

SDLU_END