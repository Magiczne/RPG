#include "IShop.h"

using namespace Items;
using namespace Encounters;

using namespace System;
using namespace System::Collections::Generic;

IShop::IShop(String^ configFile) 
	: IEncounter(configFile)
{
	this->_availableItems = gcnew List<IItem^>();
}

List<IItem^>^ IShop::AvailableItems::get()
{
	return this->_availableItems;
}