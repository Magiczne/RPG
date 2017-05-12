#include "ILocation.h"

using namespace Encounters;
using namespace Locations;
using namespace UI;

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

ILocation::ILocation(String^ configFile)
{
	this->_configFile = configFile;

	this->_availableEncounters = gcnew List<IEncounter^>();
	this->_neighbourLocations = gcnew List<ILocation^>();

	auto lines = File::ReadAllLines(this->ConfigFile);
	this->Name = lines[0];
	this->Description = lines[1];
}

#pragma region Getters

String^ ILocation::Name::get()
{
	return this->_name;
}

String^ ILocation::Description::get()
{
	return this->_description;
}

String^ ILocation::ConfigFile::get()
{
	return this->_configFile;
}

List<IEncounter^>^ ILocation::AvailableEncounters::get()
{
	return this->_availableEncounters;
}

List<ILocation^>^ ILocation::NeighbourLocations::get()
{
	return this->_neighbourLocations;
}

IUserInterface^ ILocation::UserInterface::get()
{
	return this->_userInterface;
}

#pragma endregion

#pragma region Setters

void ILocation::Name::set(String^ value)
{
	this->_name = value;
}

void ILocation::Description::set(String^ value)
{
	this->_description = value;
}

void ILocation::UserInterface::set(IUserInterface^ value)
{
	this->_userInterface = value;
}

#pragma endregion
