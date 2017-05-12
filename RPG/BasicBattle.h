#pragma once

#include "ICharacter.h"
#include "IBattle.h"

namespace Encounters
{
	public ref class BasicBattle
		: public IBattle
	{
	public:
		BasicBattle(System::String^ configFile);

		/// <summary>
		/// Starts a fight with character
		/// </summary>
		/// <exception cref="PlayerDeadException"></exception>
		/// <param name="character">Character to fight with</param>
		virtual void fight(ICharacter^ character) override;
	};
}