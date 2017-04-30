#include "stdafx.h"
#include "Character.h"

using namespace System;

Character::Character(String^ desc, Statistics^ stats) 
	: Character(desc, stats, false)
{
}


Character::Character(String^ desc, Statistics^ stats, bool player)
{
	this->Description = desc;
	this->_statistics = stats;
	this->_equipment = gcnew Equipment;

	if(player)
	{
		this->_statistics->add(gcnew Statistics(0, 0, 0, 0, 0, 0, 0, 100));
	}
}

String^ Character::Description::get()
{
	return this->_description;
}

void Character::Description::set(String^ value)
{
	this->_description = value;
}

int Character::getMaxHp()
{
	return this->_statistics->Toughness * 5;
}

int Character::getMaxMana()
{
	return this->_statistics->Intelligence * 5;
}

int Character::baseMeleeAttack()
{
	//TODO: Melee is strength?
	return this->_statistics->Strength * 2;
}

int Character::baseRangeAttack()
{
	//TODO: Ranged is agility?
	return this->_statistics->Agility * 2;
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