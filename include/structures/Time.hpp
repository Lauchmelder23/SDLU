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

	template<typename Rep = Int64, typename Period = std::ratio<1>> std::chrono::duration<Rep, Period> AsChrono() const;
	std::chrono::seconds AsChronoSeconds() const;
	std::chrono::milliseconds AsChronoMilliseconds() const;
	std::chrono::microseconds AsChronoMicroseconds() const;

	template<typename Rep, typename Period> friend Time Create(const Rep& duration);
	template<typename Rep, typename Period> friend Time Create(const std::chrono::duration<Rep, Period>& duration);
	friend Time Seconds(float seconds);
	friend Time Milliseconds(Int32 milliseconds);
	friend Time Microseconds(Int64 microseconds);

	friend bool operator==(const Time& left, const Time& right);
	friend bool operator!=(const Time& left, const Time& right);
	friend bool operator<(const Time& left, const Time& right);
	friend bool operator>(const Time& left, const Time& right);
	friend bool operator<=(const Time& left, const Time& right);
	friend bool operator>=(const Time& left, const Time& right);

	friend Time operator-(const Time& right);

	friend Time operator+(const Time& left, const Time& right);
	friend Time& operator+=(Time& left, const Time& right);

	friend Time operator-(const Time& left, const Time& right);
	friend Time& operator-=(Time& left, const Time& right);

	friend Time operator*(const Time& left, float right);
	friend Time operator*(const Time& left, Int64 right);
	friend Time operator*(float left, const Time& right);
	friend Time operator*(Int64 left, const Time& right);
	friend Time& operator*=(Time& left, float right);
	friend Time& operator*=(Time& left, Int64 right);

	friend Time operator/(const Time& left, float right);
	friend Time operator/(const Time& left, Int64 right);
	friend Time& operator/=(Time& left, float right);
	friend Time& operator/=(Time& left, Int64 right);
	friend float operator/(const Time& left, const Time& right);

	friend Time operator%(const Time& left, const Time& right);
	friend Time& operator%=(Time& left, const Time& right);

private:
	std::chrono::duration<Int64, std::micro> microseconds;
};


template<typename Rep, typename Period>
inline Rep Time::AsValue() const
{
	return std::chrono::duration_cast<std::chrono::duration<Rep, Period>>(microseconds).count();
}

template<typename Rep, typename Period>
inline std::chrono::duration<Rep, Period> Time::AsChrono() const
{
	return std::chrono::duration_cast<std::chrono::duration<Rep, Period>>(microseconds);
}

template<typename Rep = Int64, typename Period = std::ratio<1>>
inline Time Create(const Rep& duration)
{
	Time newTime;
	newTime.microseconds = std::chrono::duration_cast<std::chrono::duration<Int64, std::micro>>(std::chrono::duration<Rep, Period>(duration));
	return newTime;
}

template<typename Rep = Int64, typename Period = std::ratio<1>>
inline Time Create(const std::chrono::duration<Rep, Period>& duration)
{
	Time newTime;
	newTime.microseconds = std::chrono::duration_cast<std::chrono::duration<Int64, std::micro>>(duration);
	return newTime;
}

SDLU_END