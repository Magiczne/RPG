#pragma once

#include "ILocation.h"
#include "ICharacter.h"

public ref class IMap abstract
{
private:
	Locations::ILocation^ _startLocation;

public:
	/// <summary>
	/// Runs map with specified character
	/// </summary>
	/// <param name="character">Character on whom map to be ran</param>
	virtual void run(ICharacter^ character) abstract;

	/// <summary>
	/// Starting location
	/// </summary>
	property Locations::ILocation^ StartLocation
	{
		Locations::ILocation^ get();
		void set(Locations::ILocation^ value);
	}
};