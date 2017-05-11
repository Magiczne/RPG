#pragma once

#include "ICharacter.h"

interface class ICharacterFactory
{
	/// <summary>
	/// Creates a character
	/// </summary>
	/// <returns>Created character</returns>
	ICharacter^ createCharacter();
};