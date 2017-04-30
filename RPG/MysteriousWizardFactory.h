#pragma once
#pragma once

#include "ICharacterFactory.h"

public ref class MysteriousWizardFactory : public ICharacterFactory
{
public:
	virtual Character^ createCharacter();
};