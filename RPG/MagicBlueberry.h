#pragma once

#include "Food.h"

namespace Items
{
	public ref class MagicBlueberry : public Food
	{
	public:
		Statistics^ getStatistics() override;
	};
}