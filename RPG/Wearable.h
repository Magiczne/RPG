#pragma once

#include "Item.h"

namespace Items
{
	public ref class Wearable abstract : public Item
	{
	public:

		/// <summary>
		/// Return if item is wearable(true)
		/// </summary>
		/// <returns>Item is wearable</returns>
		bool isWearable() override;
	};
}