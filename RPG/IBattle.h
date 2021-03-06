#pragma once

#include "IEncounter.h"
#include "IOpponent.h"
#include "IReward.h"

namespace Encounters
{
	public ref class IBattle abstract
		: public IEncounter
	{
	private:
		System::String^ _name;
		System::String^ _description;
		Rewards::IReward^ _reward;
		System::Collections::Generic::List<IOpponent^>^ _opponents;

	public:
		IBattle(System::String^ configFile);

		/// <summary>
		/// Starts a fight with character
		/// </summary>
		/// <exception cref="PlayerDeadException"></exception>
		/// <param name="character">Character to fight with</param>
		virtual void fight(ICharacter^ character) abstract;

		/// <summary>
		/// Process an encounter on player.
		/// Returns false if character dies
		/// </summary>
		/// <param name="character">Character on whom encounter was proceeded</param>
		/// <returns>Encounter succedeed</returns>
		virtual bool proceed(ICharacter^ character) override;

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
		property Rewards::IReward^ Reward
		{
			Rewards::IReward^ get();
			void set(Rewards::IReward^ value);
		}

		/// <summary>
		/// Opponents in the battle
		/// </summary>
		property System::Collections::Generic::List<IOpponent^>^ Opponents 
		{
			System::Collections::Generic::List<IOpponent^>^ get();
		}
	};
}