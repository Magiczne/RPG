#pragma once

#include "IShop.h"

public ref class Shop1 : public Encounters::IShop
{
protected:
	Items::IItem^ selectedItem;
	array<System::String^>^ data;
public:
	Shop1(System::String^ conf);
	virtual void trade(ICharacter^ character)override;
	virtual bool proceed(ICharacter^ character)override;
};
