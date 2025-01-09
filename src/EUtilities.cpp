#include "EUtilities.hpp"

#include <chrono>
#include <iostream>
#include <thread>

void eutilities::resetConsoleInput()
{
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}

void eutilities::sleepFor(std::chrono::milliseconds iMsDuration)
{
	std::this_thread::sleep_for(iMsDuration);
}