#include "ILocation.h"

using namespace Encounters;
using namespace Locations;

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

ILocation::ILocation(String^ configFile)
{
	this->_configFile = configFile;

	this->_encounters = gcnew List<IEncounter^>();
	this->_neighbourLocations = gcnew List<ILocation^>();


	auto lines = File::ReadAllLines(this->_configFile);
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

List<IEncounter^>^ ILocation::Encounters::get()
{
	return this->_encounters;
}

List<ILocation^>^ ILocation::NeighbourLocations::get()
{
	return this->_neighbourLocations;
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

#pragma endregion
