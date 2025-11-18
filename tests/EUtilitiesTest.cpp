#include "EUtilities.hpp"
#include <gtest/gtest.h>

#include <chrono>
#include <ctime>

TEST(EUtilities, SleepTest)
{
	using namespace std::chrono_literals;

    std::clock_t start{ std::clock() };
	eutilities::sleepFor(1s);
	std::clock_t end{ std::clock() };
	EXPECT_GE(std::chrono::seconds(end - start), 1s);

	start = std::clock();
	eutilities::sleepFor(250ms);
	end = std::clock();
	EXPECT_GE(std::chrono::milliseconds(end - start), 250ms);
}
