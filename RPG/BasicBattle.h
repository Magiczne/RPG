#pragma once

#include "ICharacter.h"
#include "IBattle.h"

namespace Encounters
{
	public ref class BasicBattle abstract
		: public IBattle
	{
	public:
		BasicBattle(System::String^ configFile);

		/// <summary>
		/// Starts a fight with character
		/// </summary>
		/// <param name="character">Character to fight with</param>
		virtual void fight(ICharacter^ character) override;
	};
}