#pragma once

#include "CharacterFactory.h"

public ref class MysteriousWizardFactory
	: public CharacterFactory
{
public:
	virtual Character^ createCharacter();
};