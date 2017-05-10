#pragma once

#include "Opponent.h"

public ref class Orc
	: public Opponent
{
public:
	Orc(Statistics^ stats);

	virtual int baseMeleeAttack() override;
	virtual int baseRangeAttack() override;
	virtual int blockAttack() override;
};