#pragma once

#include "ICharacter.h"
#include "IOpponent.h"

public ref class MadCharacter
	: public IOpponent
{
protected:
	ICharacter^ _character;

public:
	MadCharacter(ICharacter^ character);

	virtual int baseMeleeAttack() override;
	virtual int baseRangeAttack() override;
	virtual int blockAttack() override;
};