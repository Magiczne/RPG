#pragma once

#include "Food.h"

namespace Items
{
	public ref class MagicBlueberry : public Food
	{
	public:
		/// <summary>
		/// Gets item statistics
		/// </summary>
		/// <returns>Item statistics</returns>
		Statistics^ getStatistics() override;
	};
}