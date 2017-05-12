#include "Map.h"

using namespace Locations;

using namespace System::Collections::Generic;

Map::Map()
{
	this->_locations = gcnew List<ILocation ^>();
	this->_locationsAdjacency = gcnew List<List<int>^>();

	this->StartLocation = this->_locations[0];
}

void Map::run(ICharacter^ character)
{
	auto currentLocation = this->StartLocation;

	while(true)
	{
		currentLocation = currentLocation->run(character);
	}
	//TODO: Some break case
}