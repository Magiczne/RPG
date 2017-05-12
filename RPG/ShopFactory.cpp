#include "ShopFactory.h"

#include "Shop.h"

#include "Apple.h"
#include "Bread.h"
#include "MagicBlueberry.h"

#include "Chestplate.h"
#include "Helmet.h"
#include "MagicBoots.h"

using namespace Encounters;
using namespace Encounters::Factories;
using namespace Items;

using namespace System;

IShop^ ShopFactory::create(ShopType type)
{
	auto random = gcnew Random();
	auto shop = gcnew Shop("Shop.txt");

	switch(type)
	{
	case ShopType::Groceries:
		for(int i = 0; i < random->Next(2, 4); i++)
		{
			switch(random->Next(0, 2))
			{
			case 0:
				shop->AvailableItems->Add(gcnew Apple());
				break;
			case 1:
				shop->AvailableItems->Add(gcnew Bread());
				break;
			case 2:
				shop->AvailableItems->Add(gcnew MagicBlueberry());
				break;
			}
		}
		break;

	case ShopType::EqiupmentShop:
		for(int i = 0; i < random->Next(1, 3); i++)
		{
			switch (random->Next(0, 2))
			{
			case 0:
				shop->AvailableItems->Add(gcnew Chestplate());
				break;
			case 1:
				shop->AvailableItems->Add(gcnew Helmet());
				break;
			case 2:
				shop->AvailableItems->Add(gcnew MagicBoots());
				break;
			}
		}
		break;
	}

	return shop;
}