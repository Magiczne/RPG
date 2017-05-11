#pragma once

#include "ICharacter.h"
#include "IBattle.h"

namespace Encounters
{
	public ref class BattleWithRetreat
		: public IBattle
	{
	public:
		BattleWithRetreat(System::String^ configFile);

		virtual void fight(ICharacter^ character) override;
		virtual bool proceed(ICharacter^ character) override;
	};
}