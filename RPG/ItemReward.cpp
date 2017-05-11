#include  "ItemReward.h"

using namespace Items;
using namespace Encounters::Rewards;

using namespace System::Collections::Generic;

ItemReward::ItemReward()
{
	this->_items = gcnew List<IItem^>();
}

void ItemReward::apply(ICharacter^ character)
{
	for each(auto item in this->_items)
	{
		character->Eq->add(item);
	}
}

void ItemReward::addItem(IItem^ item)
{
	this->_items->Add(item);
}