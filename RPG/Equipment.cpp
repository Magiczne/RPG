#include "stdafx.h"
#include "Equipment.h"

using namespace System::Collections::Generic;
using namespace Items;

Equipment::Equipment()
{
	_toUse = gcnew List<IItem^>();
	_inUse = gcnew List<IItem^>();
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
			//TODO: Use item
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
	
	}

	//TODO: Error handling?
}

void Equipment::unWear(int index)
{
	if (index <= this->_inUse->Count - 1)
	{
		auto item = _inUse[index];

		this->_inUse->Remove(item);
		this->_toUse->Add(item);
	}
	
	//TODO: Error handling?
}

void Equipment::add(IItem^ item)
{
	_toUse->Add(item);
}

void Equipment::remove(IItem^ item)
{
	_toUse->Remove(item);
}
