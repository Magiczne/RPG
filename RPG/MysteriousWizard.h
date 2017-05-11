#pragma once

#include "IOpponent.h"

public ref class MysteriousWizard 
	: public IOpponent
{
public:
	MysteriousWizard(Statistics^ stats);

	virtual int baseMeleeAttack() override;
	virtual int baseRangeAttack() override;
	virtual int blockAttack() override;
};