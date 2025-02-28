#include "EUtilities-Windows.hpp"

#include "EUtilities.hpp"
#include <chrono>
#include <string_view>
#include <thread>
#include <Windows.h>

using namespace std::chrono_literals;

namespace eutilities
{
	void setMouseReleaseInput(Key mouseKey, INPUT& mouseInput);
	void setMousePressInput(Key mouseKey, INPUT& mouseInput);
	constexpr bool isMouseKey(Key key);
}

constexpr bool eutilities::isMouseKey(Key key)
{
	switch (key)
	{
	case Key::LEFT_CLICK:
	case Key::RIGHT_CLICK:
	case Key::MIDDLE_MOUSE:
	case Key::MOUSE_BUTTON1:
	case Key::MOUSE_BUTTON2:
		return true;
	}

	return false;
}

void eutilities::setMousePressInput(Key mouseKey, INPUT& mouseInput)
{
	mouseInput.type = INPUT_MOUSE;

	switch (mouseKey)
	{
	case Key::LEFT_CLICK:
		mouseInput.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		break;
	case Key::RIGHT_CLICK:
		mouseInput.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
		break;
	case Key::MIDDLE_MOUSE:
		mouseInput.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
		break;
	case Key::MOUSE_BUTTON1:
		mouseInput.mi.dwFlags = MOUSEEVENTF_XDOWN;
		mouseInput.mi.mouseData = XBUTTON1;
		break;
	case Key::MOUSE_BUTTON2:
		mouseInput.mi.dwFlags = MOUSEEVENTF_XDOWN;
		mouseInput.mi.mouseData = XBUTTON2;
		break;
	}
}

void eutilities::setMouseReleaseInput(Key mouseKey, INPUT& mouseInput)
{
	mouseInput.type = INPUT_MOUSE;

	switch (mouseKey)
	{
	case Key::LEFT_CLICK:
		mouseInput.mi.dwFlags = MOUSEEVENTF_LEFTUP;
		break;
	case Key::RIGHT_CLICK:
		mouseInput.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
		break;
	case Key::MIDDLE_MOUSE:
		mouseInput.mi.dwFlags = MOUSEEVENTF_MIDDLEUP;
		break;
	case Key::MOUSE_BUTTON1:
		mouseInput.mi.dwFlags = MOUSEEVENTF_XUP;
		mouseInput.mi.mouseData = XBUTTON1;
		break;
	case Key::MOUSE_BUTTON2:
		mouseInput.mi.dwFlags = MOUSEEVENTF_XUP;
		mouseInput.mi.mouseData = XBUTTON2;
		break;
	}
}

std::vector<eutilities::Key> eutilities::getPressedKeys()
{
	std::vector<Key> pressedKeys;
	std::array<BYTE, 256> keyStates{};
	if (GetKeyboardState(keyStates.data()))
	{
		for (Key i : keys)
		{
			if (keyStates[static_cast<int>(i)] & 0b1000'0000)
			{
				pressedKeys.push_back(i);
			}
		}
	}
	return pressedKeys;
}

void eutilities::waitForKeyPressAndRelease(Key key)
{
	waitForKeyPress(key);
	waitForKeyRelease(key);
}

void eutilities::waitForKeyPress(Key key)
{
	while (!isPressed(key))
	{
		sleepFor(1ms);
	}
}

void eutilities::waitForKeyRelease(Key key)
{
	while (isPressed(key))
	{
		sleepFor(1ms);
	}
}

void eutilities::keyPress(Key key)
{
	INPUT input{};
	if (isMouseKey(key))
	{
		setMousePressInput(key, input);
	}
	else
	{
		input.type = INPUT_KEYBOARD;
		input.ki.wVk = key;
	}

	SendInput(1, &input, sizeof(INPUT));
}

void eutilities::keyRelease(Key key)
{
	INPUT input{};
	if (isMouseKey(key))
	{
		setMouseReleaseInput(key, input);
	}
	else
	{
		input.type = INPUT_KEYBOARD;
		input.ki.wVk = key;
		input.ki.dwFlags = KEYEVENTF_KEYUP;
	}
	SendInput(1, &input, sizeof(INPUT));
}

void eutilities::keyPressAndRelease(Key key)
{
	keyPress(key);
	sleepFor(30ms);
	keyRelease(key);
}

void eutilities::humanType(std::wstring_view string, std::chrono::milliseconds keyPressInterval)
{
	INPUT input{};
	input.type = INPUT_KEYBOARD;

	for (auto i : string)
	{
		input.ki.dwFlags = KEYEVENTF_UNICODE;
		input.ki.wScan = i;
		SendInput(1, &input, sizeof(INPUT));

		sleepFor(20ms);

		input.ki.dwFlags = KEYEVENTF_UNICODE | KEYEVENTF_KEYUP;
		SendInput(1, &input, sizeof(INPUT));

		sleepFor(keyPressInterval);
	}
}

bool eutilities::isPressed(Key key)
{
	return GetKeyState(key) & 0x8000;
}

bool eutilities::isPressed(int key)
{
	return isPressed(static_cast<Key>(key));
}