#pragma once

#include "Character.h"

public ref class Warrior
	: Character
{
public:
	Warrior();

	virtual int baseMeleeAttack() override;
	virtual int baseRangeAttack() override;
	virtual int blockAttack() override;
};