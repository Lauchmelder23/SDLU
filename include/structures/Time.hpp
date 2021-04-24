/*****************************************************************//**
 * @file   Time.hpp
 * @brief  A wrapper around std::chrono::duration
 * 
 * @author Lauchmelder
 * @date   April 2021
 *********************************************************************/


#pragma once

#include <chrono>

#include "Util.hpp"

SDLU_BEGIN

typedef Int64		TimeRep;
typedef std::nano	TimePeriod;

/**
 * @brief This class wraps std::chrono::duration and defines some conversions for commonly used times
 */
class Time {
public:
	/**
	 * @brief Default constructor. Constructs a time with value 0
	 */
	Time();

	/**
	 * @brief Returns the stored time in the specified format as a scalar.
	 * 
	 * @tparam Rep The datatype to be returned
	 * @tparam Period An std::ratio representing the resolution of the time format. E.g. the number of seconds per time step
	 * 
	 * @return A scalar value representing the stored time
	 */
	template<typename Rep = Int64, typename Period = std::ratio<1>> 
	Rep AsValue() const;

	/**
	 * @brief Returns the stored time in seconds
	 */
	float AsSeconds() const;

	/**
	 * @brief Returns the stored time in milliseconds
	 */
	Int32 AsMilliseconds() const;

	/**
	 * @brief Returns the stored time in microseconds
	 */
	Int64 AsMicroseconds() const;


	/**
	 * @brief Returns the stored time in the specified format as a std::duration.
	 *
	 * @tparam Rep The datatype to be returned
	 * @tparam Period An std::ratio representing the resolution of the time format. E.g. the number of seconds per time step
	 *
	 * @return A std::duration value representing the stored time
	 */
	template<typename Rep = Int64, typename Period = std::ratio<1>> 
	std::chrono::duration<Rep, Period> AsChrono() const;

	/**
	 * @brief Returns the stored time in std::chrono::seconds
	 */
	std::chrono::seconds AsChronoSeconds() const;

	/**
	 * @brief Returns the stored time in std::chrono::milliseconds
	 */
	std::chrono::milliseconds AsChronoMilliseconds() const;

	/**
	 * @brief Returns the stored time in std::chrono::microseconds
	 */
	std::chrono::microseconds AsChronoMicroseconds() const;


	/**
	 * @brief Stores the given scalar as a time, using the given format.
	 * 
	 * @tparam Rep The datatype to be returned
	 * @tparam Period An std::ratio representing the resolution of the time format. E.g. the number of seconds per time step
	 * 
	 * @return A Time object storing the given scalar
	 */
	template<typename Rep = Int64, typename Period = std::ratio<1>> 
	static Time Create(const Rep& duration);

	/**
	 * @brief Stores the given std::duration.
	 *
	 * @tparam Rep The datatype to be returned
	 * @tparam Period An std::ratio representing the resolution of the time format. E.g. the number of seconds per time step
	 *
	 * @return A Time object storing the given std::duration
	 */
	template<typename Rep = Int64, typename Period = std::ratio<1>> 
	static Time Create(const std::chrono::duration<Rep, Period>& duration);

	/**
	 * @brief Creates a Time object storing the current point in time.
	 *
	 * @return A Time object storing the current time
	 */
	static Time Now();

	/**
	 * @brief Creates a Time object from a given number of seconds.
	 * 
	 * @param seconds The number of seconds to store
	 * 
	 * @ret A Time object storing the given seconds
	 */
	friend Time Seconds(float seconds);

	/**
	 * @brief Creates a Time object from a given number of milliseconds.
	 *
	 * @param seconds The number of milliseconds to store
	 *
	 * @ret A Time object storing the given milliseconds
	 */
	friend Time Milliseconds(Int32 milliseconds);

	/**
	 * @brief Creates a Time object from a given number of microseconds.
	 *
	 * @param seconds The number of microseconds to store
	 *
	 * @ret A Time object storing the given microseconds
	 */
	friend Time Microseconds(Int64 microseconds);


	/**
	 * @brief Overload of == operator comparing two Times.
	 * 
	 * @param left Left operand
	 * @param right Right operand
	 * 
	 * @return true if the two times are the same
	 */
	friend bool operator==(const Time& left, const Time& right);

	/**
	 * @brief Overload of != operator comparing two Times.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return true if the two times are not the same
	 */
	friend bool operator!=(const Time& left, const Time& right);

	/**
	 * @brief Overload of < operator comparing two Times.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return true if \p left is less than \p right
	 */
	friend bool operator<(const Time& left, const Time& right);

	/**
	 * @brief Overload of > operator comparing two Times.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return true if \p left is greater than \p right
	 */
	friend bool operator>(const Time& left, const Time& right);

	/**
	 * @brief Overload of <= operator comparing two Times.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return true if \p left is less than or equal to \p right
	 */
	friend bool operator<=(const Time& left, const Time& right);

	/**
	 * @brief Overload of < operator comparing two Times.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return true if \p left is greater than or equal to \p right
	 */
	friend bool operator>=(const Time& left, const Time& right);


	/**
	 * @brief Overload of the unary - operator.
	 *
	 * @param right Right operand
	 *
	 * @return The negated time stored in \p right
	 */
	friend Time operator-(const Time& right);


	/**
	 * @brief Overload of + operator to add two Times.
	 * 
	 * @param left Left operand
	 * @param right Right operand
	 * 
	 * @return The sum of the two times
	 */
	friend Time operator+(const Time& left, const Time& right);

	/**
	 * @brief Overload of += operator to add two Times.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return \p left
	 */
	friend Time& operator+=(Time& left, const Time& right);


	/**
	 * @brief Overload of - operator to subtract two Times.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return The difference of the two times
	 */
	friend Time operator-(const Time& left, const Time& right);

	/**
	 * @brief Overload of -= operator to subtract two Times.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return \p left
	 */
	friend Time& operator-=(Time& left, const Time& right);


	/**
	 * @brief Overload of * operator to multiply a Time with a scalar.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return \p left scaled by a factor of \p right
	 */
	friend Time operator*(const Time& left, float right);

	/**
	 * @brief Overload of * operator to multiply a Time with a scalar.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return \p left scaled by a factor of \p right
	 */
	friend Time operator*(const Time& left, Int64 right);

	/**
	 * @brief Overload of * operator to multiply a Time with a scalar.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return \p right scaled by a factor of \p left
	 */
	friend Time operator*(float left, const Time& right);

	/**
	 * @brief Overload of * operator to multiply a Time with a scalar.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return \p right scaled by a factor of \p left
	 */
	friend Time operator*(Int64 left, const Time& right);

	/**
	 * @brief Overload of *= operator to multiply a Time with a scalar.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return \p left
	 */
	friend Time& operator*=(Time& left, float right);

	/**
	 * @brief Overload of *= operator to multiply a Time with a scalar.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return \p left
	 */
	friend Time& operator*=(Time& left, Int64 right);


	/**
	 * @brief Overload of / operator to divide a Time by a scalar.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return \p left divided by \p right
	 */
	friend Time operator/(const Time& left, float right);

	/**
	 * @brief Overload of / operator to divide a Time by a scalar.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return \p left divided by \p right
	 */
	friend Time operator/(const Time& left, Int64 right);

	/**
	 * @brief Overload of /= operator to divide a Time by a scalar.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return \p left
	 */
	friend Time& operator/=(Time& left, float right);

	/**
	 * @brief Overload of /= operator to divide a Time by a scalar.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return \p left
	 */
	friend Time& operator/=(Time& left, Int64 right);

	/**
	 * @brief Overload of / operator to divide two Times
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return The ratio of two times
	 */
	friend float operator/(const Time& left, const Time& right);

	/**
	 * @brief Overload of % operator to calculate the modulo of a Time.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return \p left % \p right
	 */
	friend Time operator%(const Time& left, const Time& right);

	/**
	 * @brief Overload of % operator to calculate the modulo of a Time.
	 *
	 * @param left Left operand
	 * @param right Right operand
	 *
	 * @return \p left
	 */
	friend Time& operator%=(Time& left, const Time& right);

private:
	std::chrono::duration<TimeRep, TimePeriod> microseconds;
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

template<typename Rep, typename Period>
inline Time Time::Create(const Rep& duration)
{
	Time newTime;
	newTime.microseconds = std::chrono::duration_cast<std::chrono::duration<TimeRep, TimePeriod>>(std::chrono::duration<Rep, Period>(duration));
	return newTime;
}

template<typename Rep, typename Period>
inline Time Time::Create(const std::chrono::duration<Rep, Period>& duration)
{
	Time newTime;
	newTime.microseconds = std::chrono::duration_cast<std::chrono::duration<TimeRep, TimePeriod>>(duration);
	return newTime;
}

inline Time Time::Now()
{
	return Create(std::chrono::steady_clock::now().time_since_epoch());
}

SDLU_END