#pragma once

#include "Statistics.h"

public ref class StatisticsFactory
{
public:
	static Statistics^ onlyMana(int mana);
};