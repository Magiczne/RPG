#pragma once

#include "ICharacterFactory.h"

public ref class GiantWaspFactory : public ICharacterFactory
{
public:
	virtual Character^ createCharacter();
};