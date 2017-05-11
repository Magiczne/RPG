#pragma once

#include "ICharacter.h"
#include "ICharacterFactory.h"

public ref class MysteriousWizardFactory
	: public ICharacterFactory
{
public:

	/// <summary>
	/// Creates a Mysterious Wizard
	/// </summary>
	/// <returns>Created character</returns>
	virtual ICharacter^ createCharacter();
};