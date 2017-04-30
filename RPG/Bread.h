#pragma once

#include "Food.h"

namespace Items
{
	public ref class Bread : public Food
	{
	public:
		Statistics^ getStatistics() override;
	};
}