#pragma once

#include "Battle.h"

namespace Encounters
{
	public ref class BattleWithRetreat
		: public Battle
	{
	public:
		BattleWithRetreat();

		virtual void fight(Character^ character) override;
		virtual bool proceed() override;
	};
}