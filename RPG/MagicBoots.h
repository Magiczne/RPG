#pragma once

#include "Wearable.h"

namespace Items
{
	public ref class MagicBoots : public Wearable
	{
	public:
		Statistics^ getStatistics() override;
	};
}