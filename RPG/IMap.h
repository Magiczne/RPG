#pragma once

#include "ILocation.h"
#include "ICharacter.h"

public ref class IMap abstract
{
private:
	Locations::ILocation^ startLocation;

public:
	void run(ICharacter^ character);
};