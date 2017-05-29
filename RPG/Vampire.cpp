#include "Vampire.h"

Vampire::Vampire(System::String^ des, Statistics^ st)
	: IOpponent(st)
{
	this->Description = des;
	//this->statistics = st;
}

int Vampire::baseMeleeAttack()
{
	return this->Stats->Agility * 2;
}

int Vampire::baseRangeAttack()
{
	return this->Stats->Strength * 2;
}

int Vampire::blockAttack()
{
	return this->Stats->HP * 2;
}