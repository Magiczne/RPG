#pragma once

#include "IShopFactory.h"

namespace Encounters
{
	namespace Factories
	{
		public ref class ShopFactory
			: IShopFactory
		{
		public:
			/// <summary>
			/// Creates a shop of specified type
			/// </summary>
			/// <param name="type">Shop type</param>
			/// <returns>Shop instance</returns>
			virtual IShop^ create(ShopType type);
		};
	}
}