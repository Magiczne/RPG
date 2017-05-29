#pragma once

#include "IFood.h"

ref class BigBurger : public Items::IFood
{
public:
	virtual Statistics^ getStatistics() override;
};