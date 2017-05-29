#pragma once

#include "IWearable.h"
#include "Chocolates.h"

ref class AmuletAdapter : public Items::IWearable
{
private:
	Chocolates _chocolates;
public:
	AmuletAdapter()
	{
		this->Stats = _chocolates.Stats;
	}
};