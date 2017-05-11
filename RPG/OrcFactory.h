#pragma once

#include "ICharacter.h"
#include "ICharacterFactory.h"

public ref class OrcFactory 
	: public ICharacterFactory
{
public:
	virtual ICharacter^ createCharacter();
};