#include "EUtilities.hpp"

#include <chrono>
#include <thread>

void eutilities::sleepFor(std::chrono::milliseconds iMsDuration)
{
	std::this_thread::sleep_for(iMsDuration);
}