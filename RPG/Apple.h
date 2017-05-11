#pragma once

#include "IFood.h"
#include "Statistics.h"

namespace Items
{
	public ref class Apple 
		: public IFood
	{
	public:
		/// <summary>
		/// Gets item statistics
		/// </summary>
		/// <returns>Item statistics</returns>
		Statistics^ getStatistics() override;
	};
}