#pragma once

#include "IItem.h"

namespace Items
{
	public ref class IWearable abstract 
		: public IItem
	{
	public:

		/// <summary>
		/// Return if item is wearable(true)
		/// </summary>
		/// <returns>Item is wearable</returns>
		bool isWearable() override;
	};
}