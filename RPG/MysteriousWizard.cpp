#include "MysteriousWizard.h"
#include "StatisticsFactory.h"

MysteriousWizard::MysteriousWizard(Statistics^ stats) 
	: IOpponent(stats)
{
	this->Description = "Mysterious Wizard";
}

int MysteriousWizard::baseMeleeAttack()
{
	return this->_statistics->Intelligence * 2;
}

int MysteriousWizard::baseRangeAttack()
{
	if(this->_statistics->Mana > 0)
	{
		this->_statistics->substract(StatisticsFactory::onlyMana(1));
		return this->_statistics->Intelligence * 2;
	}
	else
	{
		return 0;
		//TODO: Maybe exception?
	}
}

int MysteriousWizard::blockAttack()
{
	return 1;
}