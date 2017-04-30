#include "stdafx.h"
#include "Chestplate.h"

using namespace Items;

Statistics^ Chestplate::getStatistics()
{
	return gcnew Statistics(0, 0, 0, 5, 0, 1, 0, 0);
}