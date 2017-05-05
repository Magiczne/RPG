#pragma once

#include "Character.h"

interface class CharacterFactory
{
	/// <summary>
	/// Creates a character
	/// </summary>
	/// <returns>Created character</returns>
	Character^ createCharacter();
};