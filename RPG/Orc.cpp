#include "Orc.h"

Orc::Orc(Character^ character) : Opponent(character)
{
	
}

int Orc::baseMeleeAttack()
{
	return this->_statistics->Strength * 2;
}

int Orc::baseRangeAttack()
{
	return this->_statistics->Agility * 1.5;
}

int Orc::blockAttack()
{
	return this->_statistics->Toughness * 2;
}