#pragma once

#include "Item.h"

public ref class Equipment
{
private:
	int _maxCapacity = 4;
	System::Collections::Generic::List<Items::Item^>^ _toUse;
	System::Collections::Generic::List<Items::Item^>^ _inUse;

public:
	Equipment();

	void use(int index);
	void wear(int index);
	void unWear(int index);
	void add(Items::Item^ item);
	void remove(Items::Item^ item);
};