#pragma once

#include "IOpponent.h"

public ref class GiantWasp
	: public IOpponent
{
public:
	GiantWasp(Statistics^ stats);

	virtual int baseMeleeAttack() override;
	virtual int baseRangeAttack() override;
	virtual int blockAttack() override;
};