#include "KillCountManager.h"

using namespace Achievements;

using namespace System;
using namespace System::Collections::Generic;

KillCountManager::KillCountManager() 
	: IAchievementManager()
{
	
}

KillCountManager::KillCountManager(const KillCountManager%)
{
	throw gcnew InvalidOperationException("Singleton cannot be coppied");
}

KillCountManager^ KillCountManager::Instance::get()
{
	return %KillCountManager::_instance;
}

void KillCountManager::addKills(int kills)
{
	this->Kills += kills;

	this->notifyAll();
}

int KillCountManager::Kills::get()
{
	return this->_kills;
}

void KillCountManager::Kills::set(int value)
{
	this->_kills = value;
}

void KillCountManager::notifyAll()
{
	String^ message;

	if(this->Kills == 1)
	{
		message = "One kill";
	}
	else if(this->Kills == 5)
	{
		message = "Five down, many to go";
	}
	else if(this->Kills == 10)
	{
		message = "10 Kills";
	}

	for each (auto listener in this->Listeners)
	{
		listener->achievementUnlocked(message);
	}
}