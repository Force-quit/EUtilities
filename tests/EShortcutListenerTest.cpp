#include "EUtilities.hpp"
#include "EShortcutListener.hpp"
#include <print>
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include <gtest/gtest.h>

using eutilities::Key;
using eutilities::EShortcutListener;

TEST(EShortcutListener, InitializerListConstructor)
{
	EShortcutListener listener{ Key::A, Key::B, Key::C };
	EXPECT_TRUE(std::ranges::equal(listener.targetKeys(), std::vector{ Key::A, Key::B, Key::C }));
}

TEST(EShortcutListener, IsListening)
{
	EShortcutListener listener;
	EXPECT_FALSE(listener.isListening());
	listener.setTargetKeys(Key::A);
	EXPECT_FALSE(listener.isListening());
	listener.startListening([]() {});
	EXPECT_TRUE(listener.isListening());
	listener.setTargetKeys(Key::B);
	EXPECT_TRUE(listener.isListening());
	listener.stopListening();
	EXPECT_FALSE(listener.isListening());
}

TEST(EShortcutListener, SetTargetKeys)
{
	EShortcutListener listener;
	listener.setTargetKeys({ Key::A, Key::B, Key::C });
	EXPECT_TRUE(std::ranges::equal(listener.targetKeys(), std::vector{ Key::A, Key::B, Key::C }));
	listener.setTargetKeys(Key::D);
	EXPECT_TRUE(std::ranges::equal(listener.targetKeys(), std::array{ Key::D }));
	std::array someKeys{ Key::E, Key::A, Key::D, Key::O };
	listener.setTargetKeys(someKeys);
	EXPECT_TRUE(std::ranges::equal(listener.targetKeys(), someKeys));
}

TEST(EShortcutListener, KeyDetection)
{
	std::uint8_t counter{};
	auto incrementCounter = [&counter]()
	{
		++counter;
	};

	EShortcutListener listener1{ Key::A };
	EShortcutListener listener2{ Key::S };
	listener1.startListening(incrementCounter);
	listener2.startListening(incrementCounter);
	eutilities::sleepFor(std::chrono::milliseconds(100));
	eutilities::fullKeyPress(Key::A);
	eutilities::fullKeyPress(Key::S);
	eutilities::sleepFor(std::chrono::milliseconds(100));
	listener1.stopListening();
	listener2.stopListening();
	EXPECT_EQ(counter, 2);
}