#include "IMap.h"

using namespace Locations;

ILocation^ IMap::StartLocation::get()
{
	return this->_startLocation;
}