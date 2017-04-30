#pragma once

#include "Item.h"

namespace Items
{
	public ref class Wearable abstract : public Item
	{
	public:
		bool isWearable() override;
	};
}