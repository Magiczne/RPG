#pragma once

#include "Character.h"

interface class ICharacterFactory
{
	public:
	Character^ createCharacter();
};