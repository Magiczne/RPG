#include "IShop.h"

using namespace Items;
using namespace Encounters;

using namespace System::Collections::Generic;

List<IItem^>^ Shop::AvailableItems::get()
{
	return this->_availableItems;
}