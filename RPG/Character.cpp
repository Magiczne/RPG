#include "stdafx.h"
#include "Character.h"

using namespace System;

Character::Character()
{
	this->_statistics = gcnew Statistics();
	this->_equipment = gcnew Equipment();
	this->_description = gcnew String("Desc");
}

int Character::getMaxHp()
{
	return this->_statistics->toughness() * 5;
}

int Character::getMaxMana()
{
	return this->_statistics->intelligence() * 5;
}

void Character::use(int index)
{
	this->_equipment->use(index);
	//TODO: Error handling
}

bool Character::wear(int index)
{
	this->_equipment->wear(index);
	//TODO: Error handling
}

bool Character::unWear(int index)
{
	this->_equipment->unWear(index);
	//TODO: Error handling
}

Statistics^ Character::getStatistics()
{
	return this->_statistics;
}