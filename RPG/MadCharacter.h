#pragma once

#include "Opponent.h"

public ref class MadCharacter
	: public Opponent
{
protected:
	Character^ _character;

public:
	MadCharacter(Character^ character);

	virtual int baseMeleeAttack() override;
	virtual int baseRangeAttack() override;
	virtual int blockAttack() override;
};