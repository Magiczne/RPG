#pragma once

#include "Equipment.h"
#include "Statistics.h"

public ref class Character
{
private:
	Statistics^ _statistics;
	Equipment^ _equipment;
	System::String^ _description;

public: 
	Character();
	
	int getMaxHp();
	int getMaxMana();
	int baseMeleeAttack();
	int baseRangeAttack();
	void use(int);
	bool wear(int);
	bool unWear(int);

	Statistics^ getStatistics();
};
