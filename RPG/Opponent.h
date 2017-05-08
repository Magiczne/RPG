#pragma once

#include "Character.h"

public ref class Opponent abstract
	: public Character
{
protected:
	Character^ _character;

public:
	Opponent(Character^ character);
};