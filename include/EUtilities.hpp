#pragma once

#include <chrono>
#include <thread>

namespace eutilities
{
	/**
	* Sleep for a certain time.
	*
	* @param iDuration The duration to sleep.
	*/
	template<typename Rep, typename Period>
	void sleepFor(std::chrono::duration<Rep, Period> iDuration)
	{
		std::this_thread::sleep_for(iDuration);
	}
}