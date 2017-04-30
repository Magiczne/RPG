#pragma once

#include "Character.h"

interface class ICharacterFactory
{
	Character^ createCharacter();
};