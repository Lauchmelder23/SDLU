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
	return AsChrono<long long, std::ratio<1>>();
}

std::chrono::milliseconds Time::AsChronoMilliseconds() const
{
	return AsChrono<long long, std::milli>();
}

std::chrono::microseconds Time::AsChronoMicroseconds() const
{
	return AsChrono<long long, std::micro>();
}

Time Seconds(float seconds)
{
	return Create<float>(seconds);
}

Time Milliseconds(Int32 milliseconds)
{
	return Create<Int32, std::milli>(milliseconds);
}

Time Microseconds(Int64 microseconds)
{
	return Create<Int64, std::micro>(microseconds);
}

bool operator==(const Time& left, const Time& right)
{
	return (left.microseconds == right.microseconds);
}

bool operator!=(const Time& left, const Time& right)
{
	return (left.microseconds != right.microseconds);
}

bool operator<(const Time& left, const Time& right)
{
	return (left.microseconds < right.microseconds);
}

bool operator>(const Time& left, const Time& right)
{
	return (left.microseconds > right.microseconds);
}

bool operator<=(const Time& left, const Time& right)
{
	return (left.microseconds <= right.microseconds);
}

bool operator>=(const Time& left, const Time& right)
{
	return (left.microseconds >= right.microseconds);
}

Time operator-(const Time& right)
{
	return Create(-right.microseconds);
}

Time operator+(const Time& left, const Time& right)
{
	return Create(left.microseconds + right.microseconds);
}

Time& operator+=(Time& left, const Time& right)
{
	left = left + right;
	return left;
}

Time operator-(const Time& left, const Time& right)
{
	return Create(left.microseconds - right.microseconds);
}

Time& operator-=(Time& left, const Time& right)
{
	left = left - right;
	return left;
}

Time operator*(const Time& left, float right)
{
	return Create(left.microseconds * right);
}

Time operator*(const Time& left, Int64 right)
{
	return Create(left.microseconds * right);
}

Time operator*(float left, const Time& right)
{
	return (right * left);
}

Time operator*(Int64 left, const Time& right)
{
	return (right * left);
}

Time& operator*=(Time& left, float right)
{
	left = left * right;
	return left;
}

Time& operator*=(Time& left, Int64 right)
{
	left = left * right;
	return left;
}

Time operator/(const Time& left, float right)
{
	return Create(left.microseconds / right);
}

Time operator/(const Time& left, Int64 right)
{
	return Create(left.microseconds / right);
}

Time& operator/=(Time& left, float right)
{
	left = left / right;
	return left;
}

Time& operator/=(Time& left, Int64 right)
{
	left = left / right;
	return left;
}

float operator/(const Time& left, const Time& right)
{
	return ((float)(left.AsMicroseconds()) / (float)(right.AsMicroseconds()));
}

Time operator%(const Time& left, const Time& right)
{
	return Create(left.microseconds % right.microseconds);
}

Time& operator%=(Time& left, const Time& right)
{
	left = left % right;
	return left;
}

SDLU_END