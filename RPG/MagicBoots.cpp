#include "MagicBoots.h"

using namespace Items;

Statistics^ MagicBoots::getStatistics()
{
	return gcnew Statistics(0, 0, 2, 0, 1, 2, 2, 0);
}