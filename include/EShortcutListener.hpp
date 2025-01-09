#pragma once

#include "EUtilities-Windows.hpp"
#include <functional>
#include <vector>
#include <thread>
#include <initializer_list>
#include <span>

namespace eutilities
{
	class EShortcutListener
	{
	public:
		EShortcutListener() noexcept = default;
		EShortcutListener(std::initializer_list<Key> iKeys) noexcept;

		[[nodiscard]] inline std::vector<Key> targetKeys() const
		{
			return mShortcutKeys;
		}

		[[nodiscard]] inline bool isListening() const
		{
			return mListenLoop.joinable();
		}

		void setTargetKeys(std::initializer_list<Key> iKeys);
		void setTargetKeys(const Key iKey);
		void setTargetKeys(std::span<const Key> iKeys);

		void startListening(std::function<void()> iCallbackFunction);
		void stopListening();

	private:
		void mainLoop(std::stop_token iStopToken);

		std::vector<Key> mShortcutKeys;
		std::jthread mListenLoop;
		std::function<void()> mCallbackFunction;
	};
}