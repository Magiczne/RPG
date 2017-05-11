#pragma once

#include "ICharacter.h"
#include "ICharacterFactory.h"

public ref class OrcFactory 
	: public ICharacterFactory
{
public:

	/// <summary>
	/// Creates an Orc
	/// </summary>
	/// <returns>Created character</returns>
	virtual ICharacter^ createCharacter();
};