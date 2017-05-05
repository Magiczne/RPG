#pragma once

#include "Character.h"

public ref class Opponent abstract
	: public Character
{
private:
	Character^ _character;

public:
	Opponent(Character^ character);
};