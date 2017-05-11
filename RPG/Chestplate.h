#pragma once

#include "IWearable.h"
#include "Statistics.h"

namespace Items
{
	public ref class Chestplate 
		: public IWearable
	{
	public:
		/// <summary>
		/// Gets item statistics
		/// </summary>
		/// <returns>Item statistics</returns>
		Statistics^ getStatistics() override;
	};
}