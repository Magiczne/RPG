#include "Helmet.h"

using namespace Items;

Statistics^ Helmet::getStatistics()
{
	return gcnew Statistics(0, 0, 0, 0, 5, 2, 0, 0);
}