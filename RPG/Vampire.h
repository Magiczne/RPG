#pragma once

#include "Statistics.h"
#include "IOpponent.h"

ref class Vampire : public IOpponent
{
public:
	Vampire(System::String^ des, Statistics^ st);

	virtual int baseMeleeAttack() override;
	virtual int baseRangeAttack() override;
	virtual int blockAttack() override;
};