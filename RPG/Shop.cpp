#include "Shop.h"

#include "StatisticsFactory.h"

using namespace Items;
using namespace Encounters;

using namespace System;

Shop::Shop(String^ configFile) 
	: IShop(configFile)
{
	
}

void Shop::trade(ICharacter^ character)
{
	//If player has enough gold
	if(this->SelectedItem->Price <= character->Stats->Gold)
	{
		this->AvailableItems->Remove(this->SelectedItem);

		character->Eq->add(this->SelectedItem);
		character->Stats->substract(
			StatisticsFactory::onlyGold(this->SelectedItem->Price)
		);

		_selectedItem = nullptr;
	}
	//TODO: Maybe some exception if does not have gold
}

IItem^ Shop::SelectedItem::get()
{
	return this->_selectedItem;
}

void Shop::SelectedItem::set(IItem^ value)
{
	this->_selectedItem = value;
}