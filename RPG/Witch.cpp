#include "Witch.h"


Witch::Witch(System::String^ des, Statistics^ st)
	: IOpponent(st)
{
	this->Description = des;
	//this->statistics = st;
}
int Witch::baseMeleeAttack()
{
	return this->Stats->Mana * 2;
}
int Witch::baseRangeAttack()
{
	return this->Stats->Strength * 2;
}
int Witch::blockAttack()
{
	return this->Stats->HP * 2;
}

