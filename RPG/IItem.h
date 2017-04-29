#pragma once

#include "Statistics.h"

namespace Items
{
	public interface class IItem
	{
		property System::String^ _name;
		property Statistics^ _statistics;
		property int _price;

	public:
		bool isWearable();
		Statistics^ getStatistics();
	};
}
