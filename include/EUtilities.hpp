#pragma once

#include <chrono>

namespace eutilities
{
	/**
	* Sleep for a certain time.
	*
	* @param iMsDuration The duration in milliseconds.
	*/
	void sleepFor(std::chrono::milliseconds iMsDuration);
}