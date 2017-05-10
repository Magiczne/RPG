#pragma once

#include "Opponent.h"
#include "Encounter.h"
#include "Reward.h"

namespace Encounters
{
	/// Config file structure:
	/// 1. Name
	/// 2. Description
	/// 3. Action question
	/// 4. Choose opponent question
	/// 5. Melee Attack
	/// 6. Ranged Attack
	/// 7. Block Attack
	/// 8-n. Special
	public ref class Battle abstract
		: public Encounter
	{
	private:
		System::String^ _name;
		System::String^ _description;
		Rewards::Reward^ _reward;
		System::Collections::Generic::List<Opponent^>^ _opponents;

	public:
		Battle();

		/// <summary>
		/// Starts a fight with character
		/// </summary>
		/// <param name="character">Character to fight with</param>
		virtual void fight(Character^ character) abstract;

		/// <summary>
		/// Process an encounter on player
		/// </summary>
		/// <param name="character">Character on whom encounter was proceeded</param>
		/// <returns>Encounter succedeed</returns>
		virtual bool proceed(Character^ character) override;

		/// <summary>
		/// Battle name
		/// </summary>
		property System::String^ Name 
		{
			System::String^ get();
			void set(System::String^ value);
		}

		/// <summary>
		/// Battle description
		/// </summary>
		property System::String^ Description
		{
			System::String^ get();
			void set(System::String^ value);
		}

		/// <summary>
		/// Battle reward
		/// </summary>
		property Rewards::Reward^ Reward
		{
			Rewards::Reward^ get();
			void set(Rewards::Reward^ value);
		}

		/// <summary>
		/// Opponents in the battle
		/// </summary>
		property System::Collections::Generic::List<Opponent^>^ Opponents 
		{
			System::Collections::Generic::List<Opponent^>^ get();
		}
	};
}