#include "Battle.h"

using namespace System;
using namespace System::Collections::Generic;

using namespace Encounters;
using namespace Rewards;

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