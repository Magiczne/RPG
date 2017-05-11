#include "Equipment.h"

#include "ItemNotWearableException.h"
#include "EquipmentOutOfRangeException.h"

using namespace System::Collections::Generic;
using namespace Items;

Equipment::Equipment()
{
	_toUse = gcnew List<IItem^>();
	_inUse = gcnew List<IItem^>();
}

Statistics^ Equipment::use(int index)
{
	//If index is not out of range process items
	if(index >= 0 && index <= this->_toUse->Count - 1)
	{
		auto item = _toUse[index];

		if(item->isWearable())
		{
			return this->wear(index);
		}
		else
		{
			this->remove(item);
			return item->getStatistics();
		}
	}

	//If it is not throw
	throw gcnew EquipmentOutOfRangeException;
}

Statistics^ Equipment::wear(int index)
{
	//If index is not out of range try to wear item
	if (index >= 0 && index <= this->_toUse->Count - 1)
	{
		if (this->_inUse->Count < this->_maxCapacity) 
		{	
			auto item = _toUse[index];

			//If items is wearable wear and return statistics
			if (item->isWearable())
			{
				this->_toUse->Remove(item);
				this->_inUse->Add(item);

				return item->getStatistics();
			}
			
			//If it is not throw
			throw gcnew ItemNotWearableException;
		}
	}
	
	//If it is not throw
	throw gcnew EquipmentOutOfRangeException;
}

Statistics^ Equipment::unWear(int index)
{
	//If index is not out of range try to wear item
	if (index >= 0 && index <= this->_inUse->Count - 1)
	{
		auto item = _inUse[index];

		this->_inUse->Remove(item);
		this->_toUse->Add(item);

		return item->getStatistics();
	}
	
	//If it is not throw
	throw gcnew EquipmentOutOfRangeException;
}

void Equipment::add(IItem^ item)
{
	_toUse->Add(item);
}

void Equipment::remove(IItem^ item)
{
	_toUse->Remove(item);
}