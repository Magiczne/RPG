#include "Location.h"

using namespace Locations;

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

Location::Location(String^ configFile)
	: ILocation(configFile)
{
	this->_data = File::ReadAllLines(this->ConfigFile);

	this->Name = this->_data[0];
	this->Description = this->_data[1];
}

ILocation^ Location::run(ICharacter^ character)
{
	auto question = this->_data[2];

	List<String^>^ answers = gcnew List<String^>();

	for each(auto location in this->NeighbourLocations)
	{
		answers->Add(this->_data[3] + " " + location->Name);
	}

	for(int i = 0; i < this->AvailableEncounters->Count; i++)
	{
		answers->Add(this->_data[4] + " " + (i + 1));
	}

	while(true)
	{
		auto choice = this->UserInterface->askQuestion(question, answers);

		//If choice is to move to another location return Location
		//Else proceed encounter on character
		if (choice >= 0 && choice < this->NeighbourLocations->Count)
		{
			return this->NeighbourLocations[choice];
		}
		else
		{
			this->AvailableEncounters[choice - this->NeighbourLocations->Count]->proceed(character);
		}
	}
}