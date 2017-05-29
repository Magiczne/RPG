#pragma once

#include "IWearable.h"
#include "Statistics.h"

ref class Amulet :
	public Items::IWearable
{
private:
	int price;
public:
	Statistics^ getStatistics();
};

