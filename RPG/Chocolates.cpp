#include "Chocolates.h"

Statistics^ Chocolates::getStatistics()
{
	Statistics ch(5, 0, 0, 0, 0, 0, 0, -10);
	return %ch;
}