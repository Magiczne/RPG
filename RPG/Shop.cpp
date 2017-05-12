#include "Shop.h"

#include "StatisticsFactory.h"

using namespace Items;
using namespace Encounters;

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

Shop::Shop(String^ configFile) 
	: IShop(configFile)
{
	this->_data = File::ReadAllLines(this->ConfigFile);
}

bool Shop::proceed(ICharacter^ character)
{
	auto question = this->_data[0];

	List<String^>^ answers = gcnew List<String^>();

	while(true)
	{
		answers->Clear();
		for each(auto item in this->AvailableItems)
		{
			answers->Add(item->Name);
		}
		answers->Add(this->_data[1]);

		auto choice = this->UserInterface->askQuestion(question, answers);

		if (choice == answers->Count - 1)
		{
			return true;
		}
		else
		{
			this->SelectedItem = this->AvailableItems[choice];
			this->trade(character);
		}
	}
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