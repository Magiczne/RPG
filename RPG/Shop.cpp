#include "Shop.h"

using namespace System::Collections::Generic;

using namespace Encounters;
using namespace Items;

List<Item^>^ Shop::Items::get()
{
	return this->_items;
}