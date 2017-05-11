#pragma once

#include "ICharacter.h"
#include "IUserInterface.h"

namespace Encounters
{
	public ref class IEncounter abstract
	{
	private:
		UI::IUserInterface^ _userInterface;

	protected:
		System::String^ _configFile;

	public:
		/// <summary>
		/// Process an encounter on player
		/// </summary>
		/// <param name="character">Character on whom encounter was proceeded</param>
		/// <returns>Encounter succedeed</returns>
		virtual bool proceed(ICharacter^ character) abstract;

		/// <summary>
		/// Interface used for the encounter
		/// </summary>
		property UI::IUserInterface^ UserInterface 
		{
			UI::IUserInterface^ get();
			void set(UI::IUserInterface^ value);
		}
	};
}