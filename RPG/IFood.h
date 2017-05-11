#pragma once

#include "IItem.h"

namespace Items
{
	public ref class IFood abstract 
		: public IItem
	{
	public:

		/// <summary>
		/// Return if item is wearable(false)
		/// </summary>
		/// <returns>Item is wearable</returns>
		bool isWearable() override;
	};
}