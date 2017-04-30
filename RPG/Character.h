#pragma once

#include "Equipment.h"
#include "Statistics.h"

public ref class Character
{
private:
	System::String^ _description;
	Statistics^ _statistics;
	Equipment^ _equipment;

public: 
	Character(System::String^ desc, Statistics^ stats);
	Character(System::String^ desc, Statistics^ stats, bool player);

	property System::String^ Description {
		System::String^ get();
		private: void set(System::String^ value);
	}
	
	int getMaxHp();
	int getMaxMana();
	int baseMeleeAttack();
	int baseRangeAttack();
	void use(int);
	bool wear(int);
	bool unWear(int);

	Statistics^ getStatistics();
};
