#pragma once

#include "Statistics.h"

namespace Items
{
	public ref class Item abstract
	{
	private:
		property System::String^ Name;
		property int Price;
		property Statistics^ Stats;

	public:
		virtual bool isWearable() abstract;
		virtual Statistics^ getStatistics() abstract;
	};
}
