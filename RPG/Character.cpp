#include "Character.h"

#include "EquipmentOutOfRangeException.h"

using namespace System;

Character::Character(Statistics^ stats)
{
	this->_statistics = stats;
	this->_equipment = gcnew Equipment;

	this->_statistics->add(gcnew Statistics(0, 0, 0, 0, 0, 0, 0, 100));
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

void Character::use(int index)
{
	try
	{
		this->_statistics->add(this->_equipment->use(index));
	}
	catch(EquipmentOutOfRangeException^)
	{
		//Do nothing basically...
	}
}

bool Character::wear(int index)
{
	try
	{
		this->_statistics->add(this->_equipment->wear(index));
		return true;
	}
	catch(EquipmentOutOfRangeException^)
	{
		return false;
	}
}

bool Character::unWear(int index)
{
	try 
	{
		this->_statistics->substract(this->_equipment->unWear(index));
		return true;
	}
	catch (EquipmentOutOfRangeException^)
	{
		return false;
	}
}

Statistics^ Character::getStatistics()
{
	return this->_statistics;
}