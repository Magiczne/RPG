#pragma once

#include "Wearable.h"

namespace Items
{
	public ref class Chestplate : public Wearable
	{
	public:
		/// <summary>
		/// Gets item statistics
		/// </summary>
		/// <returns>Item statistics</returns>
		Statistics^ getStatistics() override;
	};
}