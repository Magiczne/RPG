#pragma once

#include "IOpponent.h"
#include "Statistics.h"

ref class Witch :public IOpponent
{
public:
	virtual int baseMeleeAttack()override;
	virtual int baseRangeAttack()override;
	virtual int blockAttack()override;
	Witch(System::String^ des, Statistics^ st);
};

