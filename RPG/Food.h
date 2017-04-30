#pragma once

#include "Item.h"

namespace Items
{
	public ref class Food abstract : public Item
	{
	public:
		bool isWearable() override;
	};
}