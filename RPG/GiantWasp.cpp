#include "GiantWasp.h"

GiantWasp::GiantWasp(Character^ character) : Opponent(character)
{
	
}

int GiantWasp::baseMeleeAttack()
{
	return this->_statistics->Strength * 2;
}

int GiantWasp::baseRangeAttack()
{
	return this->_statistics->Agility * 2;
}

int GiantWasp::blockAttack()
{
	return this->_statistics->Toughness;
}