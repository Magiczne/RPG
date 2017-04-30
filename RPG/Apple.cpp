#include "stdafx.h"
#include "Apple.h"

using namespace Items;

Statistics^ Apple::getStatistics()
{
	return gcnew Statistics(10, 0, 0, 0, 0, 0, 0, 0);
}