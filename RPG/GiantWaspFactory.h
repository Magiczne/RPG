#pragma once

#include "ICharacter.h"
#include "ICharacterFactory.h"

public ref class GiantWaspFactory 
	: public ICharacterFactory
{
public:
	virtual ICharacter^ createCharacter();
};