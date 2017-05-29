#pragma once

#include "IFood.h"
#include "Statistics.h"

ref class Chocolates :
	public Items::IFood
{
private:
	int price;
public:
	Statistics^ getStatistics();
};

