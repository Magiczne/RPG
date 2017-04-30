#include "stdafx.h"
#include "MagicBlueberry.h"

using namespace Items;

Statistics^ MagicBlueberry::getStatistics()
{
	return gcnew Statistics(0, 0, 1, 0, 0, 0, 0, 0);
}