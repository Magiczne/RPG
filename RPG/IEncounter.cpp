#include "IEncounter.h"

using namespace Encounters;
using namespace UI;

using namespace System;

IEncounter::IEncounter(String^ configFile)
{
	this->_configFile = configFile;
}

#pragma region Getters

IUserInterface^ IEncounter::UserInterface::get()
{
	return this->_userInterface;
}

String^ IEncounter::ConfigFile::get()
{
	return this->_configFile;
}

#pragma endregion

#pragma region Setters

void IEncounter::UserInterface::set(UI::IUserInterface^ value)
{
	this->_userInterface = value;
}

#pragma endregion