#pragma once

#include "IBattle.h"

ref class Battle1 : public Encounters::IBattle
{
	array<System::String^>^ data;
public:
	Battle1(void);

	virtual void fight(ICharacter^ character) override;
	virtual bool proceed(ICharacter^ c) override;
};
