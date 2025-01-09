#pragma once

#include <chrono>

namespace eutilities
{
	//Reset the std::cin buffer.
	void resetConsoleInput();

	/**
	* Sleep for a certain time.
	*
	* @param iMsDuration The duration in milliseconds.
	*/
	void sleepFor(std::chrono::milliseconds iMsDuration);
}