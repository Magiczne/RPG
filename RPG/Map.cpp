#include "Map.h"

using namespace Locations;

using namespace System::Collections::Generic;

Map::Map()
{
	this->_locations = gcnew List<ILocation ^>();
	this->_locationsAdjacency = gcnew List<List<int>^>();
}