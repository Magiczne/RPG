#include "IAchievementManager.h"

using namespace Achievements;

using namespace System::Collections::Generic;

IAchievementManager::IAchievementManager()
{
	this->_listeners = gcnew List<IAchievementListener^>();
}

List<IAchievementListener^>^ IAchievementManager::Listeners::get()
{
	return this->_listeners;
}