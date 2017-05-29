#include "BigBurger.h"

Statistics^ BigBurger::getStatistics()
{
	return gcnew Statistics(0, 0, 0, 0, 20, 0, 0, 0);
}