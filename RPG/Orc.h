#pragma once

#include "IOpponent.h"

public ref class Orc
	: public IOpponent
{
public:
	Orc(Statistics^ stats);

	virtual int baseMeleeAttack() override;
	virtual int baseRangeAttack() override;
	virtual int blockAttack() override;
};