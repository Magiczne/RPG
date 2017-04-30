#pragma once

#include "ICharacterFactory.h"

public ref class OrcFactory : public ICharacterFactory
{
public:
	virtual Character^ createCharacter();
};