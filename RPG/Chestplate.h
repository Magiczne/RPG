#pragma once

#include "Wearable.h"

namespace Items
{
	public ref class Chestplate : public Wearable
	{
	public:
		Statistics^ getStatistics() override;
	};
}