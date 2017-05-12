#pragma once

#include "IShop.h"

namespace Encounters
{
	namespace Factories
	{
		enum ShopType
		{
			Groceries,
			EqiupmentShop
		};

		interface class IShopFactory 
		{
			/// <summary>
			/// Creates a shop of specified type
			/// </summary>
			/// <param name="type">Shop type</param>
			/// <returns>Shop instance</returns>
			IShop^ create(ShopType type);
		};
	}
}