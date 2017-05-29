#include "Amulet.h"

Statistics^ Amulet::getStatistics()
{
	Statistics a(0, 4, 1, 0, 0, 0, 0, -25);
	return %a;
}