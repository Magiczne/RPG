#pragma once

#include "IMap.h"
#include "ILocation.h"

public ref class Map 
	: public IMap
{
private:
	//Graph representation of the map
	System::Collections::Generic::List<Locations::ILocation^>^ _locations;
	System::Collections::Generic::List<System::Collections::Generic::List<int>^>^ _locationsAdjacency;

public:
	Map();

	/// <summary>
	/// Runs map with specified character
	/// </summary>
	/// <param name="character">Character on whom map to be ran</param>
	virtual void run(ICharacter^ character) override;

	/// <summary>
	/// List of locations
	/// </summary>
	property System::Collections::Generic::List<Locations::ILocation^>^ LocationsList
	{
		System::Collections::Generic::List<Locations::ILocation^>^ get();
	}

	/// <summary>
	/// Adjacency list of locations
	/// </summary>
	property System::Collections::Generic::List<System::Collections::Generic::List<int>^>^ LocationsAdjacency
	{
		System::Collections::Generic::List<System::Collections::Generic::List<int>^>^ get();
	}
};