#pragma once

#include "ICharacter.h"

public ref class Warrior
	: ICharacter
{
public:
	Warrior();

	virtual int baseMeleeAttack() override;
	virtual int baseRangeAttack() override;
	virtual int blockAttack() override;
};