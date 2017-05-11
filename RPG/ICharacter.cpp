#include "ICharacter.h"

#include "EquipmentOutOfRangeException.h"

using namespace System;

ICharacter::ICharacter(Statistics^ stats)
{
	this->_statistics = stats;
	this->_equipment = gcnew Equipment;

	this->_statistics->add(gcnew Statistics(0, 0, 0, 0, 0, 0, 0, 100));
}

String^ ICharacter::Description::get()
{
	return this->_description;
}

void ICharacter::Description::set(String^ value)
{
	this->_description = value;
}

int ICharacter::getMaxHp()
{
	return this->_statistics->Toughness * 5;
}

int ICharacter::getMaxMana()
{
	return this->_statistics->Intelligence * 5;
}

void ICharacter::use(int index)
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

bool ICharacter::wear(int index)
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

bool ICharacter::unWear(int index)
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

Statistics^ ICharacter::getStatistics()
{
	return this->_statistics;
}