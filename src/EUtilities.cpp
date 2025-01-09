#include "EUtilities.hpp"

#include <chrono>
#include <iostream>
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

void eutilities::resetConsoleInput()
{
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}

void eutilities::sleepFor(std::chrono::milliseconds iMsDuration)
{
	std::this_thread::sleep_for(iMsDuration);
}

constexpr bool eutilities::isMouseKey(Key key)
{
	switch (key)
	{
	case eutilities::Key::LEFT_CLICK:
	case eutilities::Key::RIGHT_CLICK:
	case eutilities::Key::MIDDLE_MOUSE:
	case eutilities::Key::MOUSE_BUTTON1:
	case eutilities::Key::MOUSE_BUTTON2:
		return true;
	}

	return false;
}

void eutilities::setMousePressInput(Key mouseKey, INPUT& mouseInput)
{
	mouseInput.type = INPUT_MOUSE;

	switch (mouseKey)
	{
	case eutilities::Key::LEFT_CLICK:
		mouseInput.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
		break;
	case eutilities::Key::RIGHT_CLICK:
		mouseInput.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
		break;
	case eutilities::Key::MIDDLE_MOUSE:
		mouseInput.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
		break;
	case eutilities::Key::MOUSE_BUTTON1:
		mouseInput.mi.dwFlags = MOUSEEVENTF_XDOWN;
		mouseInput.mi.mouseData = XBUTTON1;
		break;
	case eutilities::Key::MOUSE_BUTTON2:
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
	case eutilities::Key::LEFT_CLICK:
		mouseInput.mi.dwFlags = MOUSEEVENTF_LEFTUP;
		break;
	case eutilities::Key::RIGHT_CLICK:
		mouseInput.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
		break;
	case eutilities::Key::MIDDLE_MOUSE:
		mouseInput.mi.dwFlags = MOUSEEVENTF_MIDDLEUP;
		break;
	case eutilities::Key::MOUSE_BUTTON1:
		mouseInput.mi.dwFlags = MOUSEEVENTF_XUP;
		mouseInput.mi.mouseData = XBUTTON1;
		break;
	case eutilities::Key::MOUSE_BUTTON2:
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
		for (eutilities::Key i : keys)
		{
			if (keyStates[static_cast<int>(i)] & 0b1000'0000)
			{
				pressedKeys.push_back(i);
			}
		}
	}
	return pressedKeys;
}

void eutilities::waitForFullKeyPress(Key key)
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

void eutilities::Console::hideCursor()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor{};
	lpCursor.bVisible = false;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

void eutilities::pressKey(Key key)
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

void eutilities::releaseKey(Key key)
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

void eutilities::fullKeyPress(Key key)
{
	pressKey(key);
	sleepFor(30ms);
	releaseKey(key);
}

void eutilities::ctrlV()
{
	pressKey(Key::CONTROL);
	sleepFor(10ms);
	pressKey(Key::V);
	sleepFor(10ms);

	releaseKey(Key::CONTROL);
	releaseKey(Key::V);
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

void eutilities::copyToClipBoard(std::span<const char> data)
{
	if (OpenClipboard(NULL))
	{
		EmptyClipboard();

		const size_t dataSize = (data.size() + 1) * sizeof(wchar_t); // Include null terminator
		HGLOBAL globalAlloc = GlobalAlloc(GMEM_MOVEABLE, dataSize);

		if (globalAlloc)
		{
			wchar_t* dataDestination = static_cast<wchar_t*>(GlobalLock(globalAlloc));
			if (dataDestination)
			{
				std::copy(data.begin(), data.end(), dataDestination);
				dataDestination[data.size()] = L'\0'; // Null terminator
				GlobalUnlock(globalAlloc);
				SetClipboardData(CF_UNICODETEXT, globalAlloc);
			}

			GlobalFree(globalAlloc);
		}

		CloseClipboard();
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