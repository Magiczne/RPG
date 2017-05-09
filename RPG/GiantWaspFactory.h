#pragma once

#include "CharacterFactory.h"

public ref class GiantWaspFactory 
	: public CharacterFactory
{
public:
	virtual Character^ createCharacter();
};