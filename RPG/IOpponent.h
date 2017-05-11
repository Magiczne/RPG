#pragma once

#include "ICharacter.h"

public ref class IOpponent abstract
	: public ICharacter
{
public:
	IOpponent(Statistics^ stats);
};