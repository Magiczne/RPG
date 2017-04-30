#pragma once

#include "Wearable.h"

namespace Items
{
	public ref class Helmet : public Wearable
	{
	public:
		Statistics^ getStatistics() override;
	};
}