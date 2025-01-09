#include "EUtilities.hpp"
#include <gtest/gtest.h>

TEST(EUtilities, SleepTest)
{
	using namespace std::chrono_literals;

	std::chrono::milliseconds sleepTime{ 1s };
    std::clock_t start{ std::clock() };
	eutilities::sleepFor(sleepTime);
	std::clock_t end{ std::clock() };
	EXPECT_GE(std::chrono::milliseconds(end - start), sleepTime);

	sleepTime = 250ms;
	start = std::clock();
	eutilities::sleepFor(sleepTime);
	end = std::clock();
	EXPECT_GE(std::chrono::milliseconds(end - start), sleepTime);
}
