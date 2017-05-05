#pragma once

#include "Item.h"

namespace Items
{
	public ref class Food abstract : public Item
	{
	public:

		/// <summary>
		/// Return if item is wearable(false)
		/// </summary>
		/// <returns>Item is wearable</returns>
		bool isWearable() override;
	};
}