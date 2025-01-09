#include "EUtilities.hpp"

#include <vector>
#include <string>
#include <print>
#include <span>

void printPressedKeys(std::span<eutilities::Key> pressedKeys)
{
	std::print("Pressing : ");

	for (auto i : pressedKeys)
	{
		std::print("{} ", eutilities::nameOf(i));
	}

	std::println("");
}

int main()
{
	while (!eutilities::isPressed(eutilities::ESCAPE))
	{
		std::vector<eutilities::Key> pressedKeys(eutilities::getPressedKeys());

		if (!pressedKeys.empty())
		{
			printPressedKeys(pressedKeys);
			pressedKeys.clear();
		}

		eutilities::sleepFor(std::chrono::milliseconds(1));
	}
}