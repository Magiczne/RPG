#include "IBattle.h"

#include "PlayerDeadException.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

using namespace Encounters;
using namespace Rewards;

IBattle::IBattle()
{
	auto lines = File::ReadAllLines(this->_configFile);

	this->Name = lines[0];
	this->Description = lines[1];
}

bool IBattle::proceed(ICharacter^ character)
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

String^ IBattle::Name::get()
{
	return this->_name;
}

String^ IBattle::Description::get()
{
	return this->_description;
}

IReward^ IBattle::Reward::get()
{
	return this->_reward;
}

List<IOpponent^>^ IBattle::Opponents::get()
{
	return this->_opponents;
}

#pragma endregion

#pragma region Setters

void IBattle::Name::set(String^ value)
{
	this->_name = value;
}

void IBattle::Description::set(String^ value)
{
	this->_description = value;
}

void IBattle::Reward::set(Rewards::IReward^ value)
{
	this->_reward = value;
}

#pragma endregion