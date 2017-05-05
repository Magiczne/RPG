#pragma once

#include "Character.h"

interface class ICharacterFactory
{
	/// <summary>
	/// Creates a character
	/// </summary>
	/// <returns>Created character</returns>
	Character^ createCharacter();
};