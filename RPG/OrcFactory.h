#pragma once

#include "CharacterFactory.h"

public ref class OrcFactory 
	: public CharacterFactory
{
public:
	virtual Character^ createCharacter();
};