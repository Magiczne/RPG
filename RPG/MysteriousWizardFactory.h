#pragma once

#include "ICharacter.h"
#include "ICharacterFactory.h"

public ref class MysteriousWizardFactory
	: public ICharacterFactory
{
public:
	virtual ICharacter^ createCharacter();
};