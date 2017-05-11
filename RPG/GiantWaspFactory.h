#pragma once

#include "ICharacter.h"
#include "ICharacterFactory.h"

public ref class GiantWaspFactory 
	: public ICharacterFactory
{
public:

	/// <summary>
	/// Creates a Giant Wasp
	/// </summary>
	/// <returns>Created character</returns>
	virtual ICharacter^ createCharacter();
};