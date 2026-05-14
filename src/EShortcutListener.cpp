#include "EShortcutListener.hpp"

#include "EUtilities.hpp"
#include "EUtilities-Windows.hpp"

#include <functional>
#include <vector>
#include <initializer_list>
#include <span>
#include <thread>

namespace eutilities
{
	void EShortcutListener::startListening(std::function<void()> iCallbackFunction)
	{
		stopListening();
		mCallbackFunction = std::move(iCallbackFunction);
		mListenLoop = std::jthread(std::bind_front(&EShortcutListener::mainLoop, this));
	}

	void EShortcutListener::stopListening()
	{
		if (mListenLoop.joinable())
		{
			mListenLoop.request_stop();
			mListenLoop.join();
		}
	}

	void EShortcutListener::mainLoop(std::stop_token iStopToken)
	{
		uint8_t pressedKeysCount{};
		bool canTrigger{ true };

		while (!iStopToken.stop_requested())
		{
			for (eutilities::Key i : mShortcutKeys)
			{
				if (eutilities::isPressed(i))
				{
					++pressedKeysCount;
					if (pressedKeysCount == mShortcutKeys.size() && canTrigger)
					{
						mCallbackFunction();
						canTrigger = false;
					}
				}
				else
				{
					pressedKeysCount = 0;
					canTrigger = true;
				}
			}

			eutilities::sleepFor(std::chrono::milliseconds(5));
		}
	}

	EShortcutListener::EShortcutListener(std::initializer_list<Key> iKeys) noexcept
		: mShortcutKeys{ iKeys }
	{

	}

	// C++26 converts initializer list to span, but for now we need this overload
	void EShortcutListener::setTargetKeys(std::initializer_list<Key> iKeys)
	{
		mShortcutKeys.assign_range(iKeys);
	}

	void EShortcutListener::setTargetKeys(std::span<Key> iKeys)
	{
		mShortcutKeys.assign_range(iKeys);
	}
}