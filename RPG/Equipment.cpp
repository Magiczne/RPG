#include "stdafx.h"
#include "Equipment.h"
#include "EquipmentIndexOutOfRangeException.h"

using namespace System::Collections::Generic;
using namespace Items;

Equipment::Equipment()
{
	_toUse = gcnew List<Item^>();
	_inUse = gcnew List<Item^>();
}

void Equipment::use(int index)
{
	if(index <= this->_toUse->Count - 1)
	{
		auto item = _toUse[index];

		if(item->isWearable())
		{
			this->wear(index);
		}
		else
		{
			this->remove(item);
		}
	}

	//TODO: Error handling
}

void Equipment::wear(int index)
{
	if(
		index <= this->_toUse->Count - 1 && 
		this->_inUse->Count < this->_maxCapacity
	)
	{
		auto item = _toUse[index];

		if(item->isWearable())
		{
			this->_toUse->Remove(item);
			this->_inUse->Add(item);
		}
	}
	else
	{
		throw gcnew EquipmentIndexOutOfRangeException();
	}
}

void Equipment::unWear(int index)
{
	if (index <= this->_inUse->Count - 1)
	{
		auto item = _inUse[index];

		this->_inUse->Remove(item);
		this->_toUse->Add(item);
	}
	else
	{
		throw gcnew EquipmentIndexOutOfRangeException();
	}
}

void Equipment::add(Item^ item)
{
	_toUse->Add(item);
}

void Equipment::remove(Item^ item)
{
	_toUse->Remove(item);
}
