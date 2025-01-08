#include "EUtilities.h"
#include <cassert>
#include <vector>
#include <chrono>


int main()
{
	eutilities::pressKey(eutilities::Key::A);
	eutilities::sleepFor(std::chrono::milliseconds(100));
	std::vector<eutilities::Key> pressedKeys(eutilities::getPressedKeys());
	assert(pressedKeys.size() == 1);
	assert(pressedKeys[0] == eutilities::Key::UP);
}