#pragma once

#include "IWearable.h"
#include "Amulet.h"

ref class AmuletAdapter : public Items::IWearable
{
private:
	Amulet _amulet;
public:
	AmuletAdapter()
	{
		this->Stats = _amulet.Stats;
	}
};