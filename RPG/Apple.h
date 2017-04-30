#pragma once

#include "Food.h"

namespace Items
{
	public ref class Apple : public Food
	{
	public:
		Statistics^ getStatistics() override;
	};
}