#include "Battle.h"

#include "PlayerDeadException.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

using namespace Encounters;
using namespace Rewards;

Battle::Battle()
{
	auto lines = File::ReadAllLines(this->_configFile);

	this->Name = lines[0];
	this->Description = lines[1];
}

bool Battle::proceed(Character^ character)
{
	try
	{
		this->fight(character);
		this->Reward->apply(character);
		return false;
	}
	catch (PlayerDeadException^)
	{
		return true;
	}
}

#pragma region Getters

String^ Battle::Name::get()
{
	return this->_name;
}

String^ Battle::Description::get()
{
	return this->_description;
}

Reward^ Battle::Reward::get()
{
	return this->_reward;
}

List<Opponent^>^ Battle::Opponents::get()
{
	return this->_opponents;
}

#pragma endregion

#pragma region Setters

void Battle::Name::set(String^ value)
{
	this->_name = value;
}

void Battle::Description::set(String^ value)
{
	this->_description = value;
}

void Battle::Reward::set(Rewards::Reward^ value)
{
	this->_reward = value;
}

#pragma endregion