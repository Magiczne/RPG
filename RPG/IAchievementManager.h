#pragma once

#include "IAchievementListener.h"

namespace Achievements
{
	public ref class IAchievementManager abstract
	{
	private:
		System::Collections::Generic::List<IAchievementListener^>^ _listeners;

	protected:
		virtual void notifyAll() abstract;

	public:
		IAchievementManager();

		property System::Collections::Generic::List<IAchievementListener^>^ Listeners
		{
			System::Collections::Generic::List<IAchievementListener^>^ get();
		}
	};
}