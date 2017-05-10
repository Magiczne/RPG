#pragma once

#include "Character.h"

public ref class Opponent abstract
	: public Character
{
public:
	Opponent(Statistics^ stats);
};