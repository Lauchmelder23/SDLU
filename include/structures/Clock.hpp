/*****************************************************************//**
 * @file   Clock.hpp
 * @brief  A small timing utility
 * 
 * @author Lauchmelder
 * @date   April 2021
 *********************************************************************/

#pragma once

#include "Util.hpp"
#include "Time.hpp"

SDLU_BEGIN

/**
 * @brief Essentially a timer.
 */
class Clock
{
public:
	/**
	 * @brief Creates a new Clock. It has not yet been started, call Restart() before doing anything else.
	 */
	Clock();

	/**
	 * @brief Returns the time elapsed since the last Restart() call.
	 */
	Time GetElapsedTime();

	/**
	 * @brief Restarts the Clock.
	 * 
	 * @return The time elapsed since the last Restart() call.
	 */
	Time Restart();

private:
	Time lastTime;
};

SDLU_END