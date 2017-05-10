#include "Bread.h"

using namespace Items;

Statistics^ Bread::getStatistics()
{
	return gcnew Statistics(20, 5, 0, 0, 0, 0, 0, 0);
}