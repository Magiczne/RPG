#include "Warrior.h"

using namespace System;

Warrior::Warrior() 
	: ICharacter(gcnew Statistics(25, 0, 0, 2, 4, 5, 0, 0))
{
	this->Description = "Warrior";
}

int Warrior::baseMeleeAttack()
{
	return this->_statistics->Strength * 2 
			+ this->_statistics->Agility / 3;
}

int Warrior::baseRangeAttack()
{
	return this->_statistics->Agility * 2;
}

int Warrior::blockAttack()
{
	return this->_statistics->Toughness;
}