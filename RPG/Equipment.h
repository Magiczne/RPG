#pragma once

#include "IItem.h"

public ref class Equipment
{
private:
	int _maxCapacity = 4;
	System::Collections::Generic::List<Items::IItem^>^ _toUse;
	System::Collections::Generic::List<Items::IItem^>^ _inUse;

public:
	Equipment();

	void use(int index);
	void wear(int index);
	void unWear(int index);
	void add(Items::IItem^ item);
	void remove(Items::IItem^ item);
};