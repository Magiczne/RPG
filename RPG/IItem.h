#pragma once

#include "Statistics.h"

namespace Items
{
	public ref class IItem abstract
	{
	private:
		property System::String^ Name;
		property int Price;
		property Statistics^ Stats;

	public:
		/// <summary>
		/// Tells if item it is wearable or not
		/// </summary>
		/// <returns>Item is wearable</returns>
		virtual bool isWearable() abstract;

		/// <summary>
		/// Gets item statistics
		/// </summary>
		/// <returns>Item statistics</returns>
		virtual Statistics^ getStatistics() abstract;
	};
}
