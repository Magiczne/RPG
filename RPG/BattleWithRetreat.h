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

		/// <summary>
		/// Starts a fight with character
		/// </summary>
		/// <param name="character">Character to fight with</param>
		virtual void fight(ICharacter^ character) override;

		/// <summary>
		/// Process an encounter on player
		/// Returns false if character dies
		/// </summary>
		/// <param name="character">Character on whom encounter was proceeded</param>
		/// <returns>Encounter succedeed</returns>
		virtual bool proceed(ICharacter^ character) override;
	};
}