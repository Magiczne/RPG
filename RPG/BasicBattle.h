#pragma once

#include "Battle.h"

namespace Encounters
{
	public ref class BasicBattle abstract
		: public Battle
	{
	public:
		BasicBattle();

		virtual void fight(Character^ character) override;
		virtual bool proceed(Character^ character) override;
	};
}