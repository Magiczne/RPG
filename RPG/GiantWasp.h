#pragma once

#include "Opponent.h"

public ref class GiantWasp
	: public Opponent
{
public:
	GiantWasp(Statistics^ stats);

	virtual int baseMeleeAttack() override;
	virtual int baseRangeAttack() override;
	virtual int blockAttack() override;
};