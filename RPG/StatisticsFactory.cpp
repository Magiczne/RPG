#include "StatisticsFactory.h"

Statistics^ StatisticsFactory::onlyMana(int mana)
{
	return gcnew Statistics(0, mana, 0, 0, 0, 0, 0, 0);
}

Statistics^ StatisticsFactory::onlyHp(int hp)
{
	return gcnew Statistics(hp, 0, 0, 0, 0, 0, 0, 0);
}