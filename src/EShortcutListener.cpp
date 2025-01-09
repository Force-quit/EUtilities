#include "EShortcutListener.hpp"

#include "EUtilities.hpp"
#include <functional>
#include <vector>
#include <initializer_list>
#include <span>
#include <thread>

namespace eutilities
{
	void EShortcutListener::startListening(std::function<void()> iCallbackFunction)
	{
		mCallbackFunction = iCallbackFunction;
		stopListening();
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
		uint8_t pressedKeys{};
		bool canTrigger{ true };

		while (!iStopToken.stop_requested())
		{
			for (auto i : mShortcutKeys)
			{
				if (eutilities::isPressed(i))
				{
					++pressedKeys;
					if (pressedKeys == mShortcutKeys.size() && canTrigger)
					{
						mCallbackFunction();
						canTrigger = false;
					}
				}
				else
				{
					pressedKeys = 0;
					canTrigger = true;
				}
			}

			eutilities::sleepFor(std::chrono::milliseconds(5));
		}
	}

	EShortcutListener::EShortcutListener(std::initializer_list<Key> iKeys) noexcept
		: mShortcutKeys(iKeys)
	{

	}

	void EShortcutListener::setTargetKeys(std::initializer_list<Key> iKeys)
	{
		mShortcutKeys.assign_range(iKeys);
	}

	void EShortcutListener::setTargetKeys(std::span<const Key> iKeys)
	{
		mShortcutKeys.assign_range(iKeys);
	}

	void EShortcutListener::setTargetKeys(Key iKey)
	{
		mShortcutKeys.clear();
		mShortcutKeys.emplace_back(iKey);
	}
}