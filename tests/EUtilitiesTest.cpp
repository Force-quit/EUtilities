#include "EUtilities.hpp"

#include <gtest/gtest.h>
#include <chrono>
#include <ctime>

TEST(EUtilities, SleepTest)
{
	using namespace std::chrono_literals;

	auto start{ std::chrono::steady_clock::now() };
	eutilities::sleepFor(1s);
	auto end{ std::chrono::steady_clock::now() };
	EXPECT_GE(std::chrono::duration_cast<std::chrono::seconds>(end - start), 1s);

	start = std::chrono::steady_clock::now();
	eutilities::sleepFor(250ms);
	end = std::chrono::steady_clock::now();
	EXPECT_GE(std::chrono::duration_cast<std::chrono::milliseconds>(end - start), 250ms);

	start = std::chrono::steady_clock::now();
	eutilities::sleepFor(100us);
	end = std::chrono::steady_clock::now();
	EXPECT_GE(std::chrono::duration_cast<std::chrono::microseconds>(end - start), 100us);

	start = std::chrono::steady_clock::now();
	eutilities::sleepFor(100ns);
	end = std::chrono::steady_clock::now();
	EXPECT_GE(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start), 100ns);
}