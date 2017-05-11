#include "Orc.h"

Orc::Orc(Statistics^ stats) 
	: IOpponent(stats)
{
	this->Description = "Orc";
}

int Orc::baseMeleeAttack()
{
	return this->_statistics->Strength * 2;
}

int Orc::baseRangeAttack()
{
	return static_cast<int>(this->_statistics->Agility * 1.5);
}

int Orc::blockAttack()
{
	return this->_statistics->Toughness * 2;
}