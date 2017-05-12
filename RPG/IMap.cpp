#include "IMap.h"

using namespace Locations;

ILocation^ IMap::StartLocation::get()
{
	return this->_startLocation;
}

void IMap::StartLocation::set(ILocation^ value)
{
	this->_startLocation = value;
}