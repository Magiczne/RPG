#include "Map.h"

using namespace Locations;

using namespace System::Collections::Generic;

Map::Map()
{
	this->_locations = gcnew List<ILocation^>();
	this->_locationsAdjacency = gcnew List<List<int>^>();
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

List<ILocation^>^ Map::LocationsList::get()
{
	return this->_locations;
}

List<List<int>^>^ Map::LocationsAdjacency::get()
{
	return this->_locationsAdjacency;
}