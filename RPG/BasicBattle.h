#pragma once

#include "ICharacter.h"
#include "IBattle.h"

namespace Encounters
{
	public ref class BasicBattle abstract
		: public IBattle
	{
	public:
		BasicBattle();

		virtual void fight(ICharacter^ character) override;
	};
}