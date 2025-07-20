#pragma once

#include <Windows.h>
#include <string_view>
#include <string>
#include <span>
#include <array>
#include <chrono>

namespace eutilities
{
	/**
		Represents physical buttons you can press. Uses Windows virtual key codes.
	*/
	enum Key : std::uint16_t
	{
		LEFT_CLICK = VK_LBUTTON,
		RIGHT_CLICK = VK_RBUTTON,
		MIDDLE_MOUSE = VK_MBUTTON,
		MOUSE_BUTTON1 = VK_XBUTTON1,
		MOUSE_BUTTON2 = VK_XBUTTON2,

		ESCAPE = VK_ESCAPE,
		F1 = VK_F1,
		F2 = VK_F2,
		F3 = VK_F3,
		F4 = VK_F4,
		F5 = VK_F5,
		F6 = VK_F6,
		F7 = VK_F7,
		F8 = VK_F8,
		F9 = VK_F9,
		F10 = VK_F10,
		F11 = VK_F11,
		F12 = VK_F12,
		PRINT = VK_SNAPSHOT,
		SCROLL_LOCK = VK_SCROLL,
		PAUSE = VK_PAUSE,

		KEY_0 = 0x30,
		KEY_1 = 0x31,
		KEY_2 = 0x32,
		KEY_3 = 0x33,
		KEY_4 = 0x34,
		KEY_5 = 0x35,
		KEY_6 = 0x36,
		KEY_7 = 0x37,
		KEY_8 = 0x38,
		KEY_9 = 0x39,


		SHIFT = VK_LSHIFT,
		RIGHT_SHIFT = VK_RSHIFT,
		CONTROL = VK_LCONTROL,
		RIGHT_CONTROL = VK_RCONTROL,
		ALT = VK_LMENU,
		RIGHT_ALT = VK_RMENU,
		WINDOWS = VK_LWIN,
		RIGHT_WINDOWS = VK_RWIN,
		TAB = VK_TAB,
		CAPSLOCK = VK_CAPITAL,
		APPS = VK_APPS,
		ENTER = VK_RETURN,
		BACKSPACE = VK_BACK,
		SPACEBAR = VK_SPACE,

		A = 0x41,
		B = 0x42,
		C = 0x43,
		D = 0x44,
		E = 0x45,
		F = 0x46,
		G = 0x47,
		H = 0x48,
		I = 0x49,
		J = 0x4A,
		K = 0x4B,
		L = 0x4C,
		M = 0x4D,
		N = 0x4E,
		O = 0x4F,
		P = 0x50,
		Q = 0x51,
		R = 0x52,
		S = 0x53,
		T = 0x54,
		U = 0x55,
		V = 0x56,
		W = 0x57,
		X = 0x58,
		Y = 0x59,
		Z = 0x5A,

		OEM1 = 0xBA,
		OEM2 = 0xBF,
		OEM3 = 0xC0,
		OEM4 = 0xDB,
		OEM5 = 0xDC,
		OEM6 = 0xDD,
		OEM7 = 0xDE,
		OEM8 = 0xDF,

		OEM_PLUS = VK_OEM_PLUS,
		OEM_MINUS = VK_OEM_MINUS,
		OEM_PERIOD = VK_OEM_PERIOD,
		OEM_COMMA = VK_OEM_COMMA,
		OEM102 = VK_OEM_102,

		UP = VK_UP,
		DOWN = VK_DOWN,
		LEFT = VK_LEFT,
		RIGHT = VK_RIGHT,
		DEL = VK_DELETE,
		INSERT = VK_INSERT,
		HOME = VK_HOME,
		END = VK_END,
		PAGE_UP = VK_PRIOR,
		PAGE_DOWN = VK_NEXT,

		NUMPAD_0 = VK_NUMPAD0,
		NUMPAD_1 = VK_NUMPAD1,
		NUMPAD_2 = VK_NUMPAD2,
		NUMPAD_3 = VK_NUMPAD3,
		NUMPAD_4 = VK_NUMPAD4,
		NUMPAD_5 = VK_NUMPAD5,
		NUMPAD_6 = VK_NUMPAD6,
		NUMPAD_7 = VK_NUMPAD7,
		NUMPAD_8 = VK_NUMPAD8,
		NUMPAD_9 = VK_NUMPAD9,
		NUMPAD_ADD = VK_ADD,
		NUMPAD_SUBTRACT = VK_SUBTRACT,
		NUMPAD_MULTIPLY = VK_MULTIPLY,
		NUMPAD_DIVIDE = VK_DIVIDE,
		NUMPAD_CLEAR = VK_CLEAR,
		NUMPAD_LOCK = VK_NUMLOCK,
		NUMPAD_DECIMAL = VK_DECIMAL,

		UNKNOWN = 0xFFFF
	};

	// Array to iterate over all the values of the Key enum.
	constexpr std::array keys{
		LEFT_CLICK,
		RIGHT_CLICK,
		MIDDLE_MOUSE,
		MOUSE_BUTTON1,
		MOUSE_BUTTON2,
		ESCAPE,
		F1,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		F10,
		F11,
		F12,
		PRINT,
		SCROLL_LOCK,
		PAUSE,
		KEY_0,
		KEY_1,
		KEY_2,
		KEY_3,
		KEY_4,
		KEY_5,
		KEY_6,
		KEY_7,
		KEY_8,
		KEY_9,
		SHIFT,
		RIGHT_SHIFT,
		CONTROL,
		RIGHT_CONTROL,
		ALT,
		RIGHT_ALT,
		WINDOWS,
		RIGHT_WINDOWS,
		TAB,
		CAPSLOCK,
		APPS,
		ENTER,
		BACKSPACE,
		SPACEBAR,
		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,
		OEM1,
		OEM2,
		OEM3,
		OEM4,
		OEM5,
		OEM6,
		OEM7,
		OEM8,
		OEM_PLUS,
		OEM_MINUS,
		OEM_PERIOD,
		OEM_COMMA,
		OEM102,
		UP,
		DOWN,
		LEFT,
		RIGHT,
		DEL,
		INSERT,
		HOME,
		END,
		PAGE_UP,
		PAGE_DOWN,
		NUMPAD_0,
		NUMPAD_1,
		NUMPAD_2,
		NUMPAD_3,
		NUMPAD_4,
		NUMPAD_5,
		NUMPAD_6,
		NUMPAD_7,
		NUMPAD_8,
		NUMPAD_9,
		NUMPAD_ADD,
		NUMPAD_SUBTRACT,
		NUMPAD_MULTIPLY,
		NUMPAD_DIVIDE,
		NUMPAD_CLEAR,
		NUMPAD_LOCK,
		NUMPAD_DECIMAL,
	};

	// Array to iterate over the keyboard keys of the Key enum.
	constexpr std::array keyboardKeys{
		ESCAPE,
		F1,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		F10,
		F11,
		F12,
		PRINT,
		SCROLL_LOCK,
		PAUSE,
		KEY_0,
		KEY_1,
		KEY_2,
		KEY_3,
		KEY_4,
		KEY_5,
		KEY_6,
		KEY_7,
		KEY_8,
		KEY_9,
		SHIFT,
		RIGHT_SHIFT,
		CONTROL,
		RIGHT_CONTROL,
		ALT,
		RIGHT_ALT,
		WINDOWS,
		RIGHT_WINDOWS,
		TAB,
		CAPSLOCK,
		APPS,
		ENTER,
		BACKSPACE,
		SPACEBAR,
		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,
		OEM1,
		OEM2,
		OEM3,
		OEM4,
		OEM5,
		OEM6,
		OEM7,
		OEM8,
		OEM_PLUS,
		OEM_MINUS,
		OEM_PERIOD,
		OEM_COMMA,
		OEM102,
		UP,
		DOWN,
		LEFT,
		RIGHT,
		DEL,
		INSERT,
		HOME,
		END,
		PAGE_UP,
		PAGE_DOWN,
		NUMPAD_0,
		NUMPAD_1,
		NUMPAD_2,
		NUMPAD_3,
		NUMPAD_4,
		NUMPAD_5,
		NUMPAD_6,
		NUMPAD_7,
		NUMPAD_8,
		NUMPAD_9,
		NUMPAD_ADD,
		NUMPAD_SUBTRACT,
		NUMPAD_MULTIPLY,
		NUMPAD_DIVIDE,
		NUMPAD_CLEAR,
		NUMPAD_LOCK,
		NUMPAD_DECIMAL,
	};

	// Array to iterate over the mouse keys of the Key enum.
	constexpr std::array mouseKeys{
		LEFT_CLICK,
		RIGHT_CLICK,
		MIDDLE_MOUSE,
		MOUSE_BUTTON1,
		MOUSE_BUTTON2
	};

	/**
	* Get the display name of the specified key.
	*
	* @param key An enum value of eutilities::Key.
	* @return The name of the key if it's known. If not, an empty std::optional.
	*/
	[[nodiscard]] constexpr std::string_view nameOf(Key key)
	{
		switch (key)
		{
		case LEFT_CLICK:
			return "Left click";
		case RIGHT_CLICK:
			return "Right click";
		case MIDDLE_MOUSE:
			return "Middle mouse";
		case MOUSE_BUTTON1:
			return "Mouse 1";
		case MOUSE_BUTTON2:
			return "Mouse 2";
		case ESCAPE:
			return "Escape";
		case F1:
			return "F1";
		case F2:
			return "F2";
		case F3:
			return "F3";
		case F4:
			return "F4";
		case F5:
			return "F5";
		case F6:
			return "F6";
		case F7:
			return "F7";
		case F8:
			return "F8";
		case F9:
			return "F9";
		case F10:
			return "F10";
		case F11:
			return "F11";
		case F12:
			return "F12";
		case PRINT:
			return "Print";
		case SCROLL_LOCK:
			return "Scroll lock";
		case PAUSE:
			return "Pause";
		case KEY_0:
			return "0";
		case KEY_1:
			return "1";
		case KEY_2:
			return "2";
		case KEY_3:
			return "3";
		case KEY_4:
			return "4";
		case KEY_5:
			return "5";
		case KEY_6:
			return "6";
		case KEY_7:
			return "7";
		case KEY_8:
			return "8";
		case KEY_9:
			return "9";
		case TAB:
			return "Tab";
		case CAPSLOCK:
			return "Capslock";
		case SHIFT:
			return "Shift";
		case CONTROL:
			return "CTRL";
		case WINDOWS:
			return "Windows";
		case ALT:
			return "Alt";
		case SPACEBAR:
			return "Spacebar";
		case RIGHT_ALT:
			return "Right alt";
		case RIGHT_WINDOWS:
			return "Right Windows";
		case APPS:
			return "Apps";
		case RIGHT_CONTROL:
			return "Right CTRL";
		case RIGHT_SHIFT:
			return "Right shift";
		case ENTER:
			return "Enter";
		case BACKSPACE:
			return "Backspace";
		case A:
			return "A";
		case B:
			return "B";
		case C:
			return "C";
		case D:
			return "D";
		case E:
			return "E";
		case F:
			return "F";
		case G:
			return "G";
		case H:
			return "H";
		case I:
			return "I";
		case J:
			return "J";
		case K:
			return "K";
		case L:
			return "L";
		case M:
			return "M";
		case N:
			return "N";
		case O:
			return "O";
		case P:
			return "P";
		case Q:
			return "Q";
		case R:
			return "R";
		case S:
			return "S";
		case T:
			return "T";
		case U:
			return "U";
		case V:
			return "V";
		case W:
			return "W";
		case X:
			return "X";
		case Y:
			return "Y";
		case Z:
			return "Z";
		case OEM1:
			return "OEM1";
		case OEM2:
			return "OEM2";
		case OEM3:
			return "OEM3";
		case OEM4:
			return "OEM4";
		case OEM5:
			return "OEM5";
		case OEM6:
			return "OEM6";
		case OEM7:
			return "OEM7";
		case OEM8:
			return "OEM8";
		case OEM_PLUS:
			return "OEM plus";
		case OEM_MINUS:
			return "OEM minus";
		case OEM_PERIOD:
			return "OEM period";
		case OEM_COMMA:
			return "OEM comma";
		case OEM102:
			return "OEM102";
		case UP:
			return "Up";
		case DOWN:
			return "Down";
		case LEFT:
			return "Left";
		case RIGHT:
			return "Right";
		case DEL:
			return "Delete";
		case INSERT:
			return "Insert";
		case HOME:
			return "Home";
		case END:
			return "End";
		case PAGE_UP:
			return "Page up";
		case PAGE_DOWN:
			return "Page down";
		case NUMPAD_0:
			return "Numpad 0";
		case NUMPAD_1:
			return "Numpad 1";
		case NUMPAD_2:
			return "Numpad 2";
		case NUMPAD_3:
			return "Numpad 3";
		case NUMPAD_4:
			return "Numpad 4";
		case NUMPAD_5:
			return "Numpad 5";
		case NUMPAD_6:
			return "Numpad 6";
		case NUMPAD_7:
			return "Numpad 7";
		case NUMPAD_8:
			return "Numpad 8";
		case NUMPAD_9:
			return "Numpad 9";
		case NUMPAD_ADD:
			return "Numpad add";
		case NUMPAD_SUBTRACT:
			return "Numpad subtract";
		case NUMPAD_MULTIPLY:
			return "Numpad multiply";
		case NUMPAD_DIVIDE:
			return "Numpad divide";
		case NUMPAD_CLEAR:
			return "Numpad clear";
		case NUMPAD_LOCK:
			return "Numpad lock";
		case NUMPAD_DECIMAL:
			return "Numpad decimal";
		case UNKNOWN:
			[[fallthrough]];
		default:
			return "Unnamed";
		}
	}

	/**
	* Get the display name of the specified key.
	*
	* @param key An enum value of eutilities::Key.
	* @return The name of the key if it's known. If not, an empty std::optional.
	*/
	[[nodiscard]] constexpr std::string_view nameOf(int key)
	{
		return nameOf(static_cast<Key>(key));
	}

	/**
	* Check if the specified key is being pressed.
	*
	* @param key The key you want to check.
	* @return True if the key is being pressed.
	*/
	[[nodiscard]] bool isPressed(Key key);

	/**
	* Check if the specified key is being pressed.
	*
	* @param key The key you want to check.
	* @return True if the key is being pressed.
	* @overload
	*/
	[[nodiscard]] bool isPressed(int key);

	/**
	* Check what key is being pressed.
	*
	* @return A vector with all the pressed keys.
	*/
	[[nodiscard]] std::vector<Key> getPressedKeys();

	/**
	* Returns execution only when the specified
	* key was pressed and then released.
	*
	* @param key The key you want to wait for.
	*/
	void waitForKeyPressAndRelease(Key key);

	/**
	* Returns execution only when the specified
	* key was pressed.
	*
	* @param key The key you want to wait for.
	*/
	void waitForKeyPress(Key key);

	/**
	* Returns execution only when the specified
	* key was released.
	*
	* @param key The key you want to wait for.
	*/
	void waitForKeyRelease(Key key);

	/**
	* Simulates a full key press (press and release)
	* with the specified key.
	* @param key The key to press and release.
	*/
	void keyPressAndRelease(Key key);

	/**
	* Simulates a key press with the specified key.
	* @param key The key to press.
	*/
	void keyPress(Key key);

	/**
	* Simulates a key release with the specified key.
	* @param key The key to release.
	*/
	void keyRelease(Key key);

	/**
	* Simulates the typing of a string.
	*
	* @param string A sequence of unicode characters.
	* @param keyPressInterval The interval between key presses.
	*/
	void humanType(std::wstring_view string, std::chrono::milliseconds keyPressInterval = std::chrono::milliseconds(120));
}