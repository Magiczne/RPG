#pragma once

#include "Opponent.h"

public ref class MysteriousWizard 
	: public Opponent
{
public:
	MysteriousWizard(Character^ character);

	virtual int baseMeleeAttack() override;
	virtual int baseRangeAttack() override;
	virtual int blockAttack() override;
};