#pragma once

#include "Character.h"
#include "UserInterface.h"

namespace Encounters
{
	public ref class Encounter abstract
	{
	private:
		UI::UserInterface^ _userInterface;

	protected:
		System::String^ _configFile;

	public:
		/// <summary>
		/// Process an encounter on player
		/// </summary>
		/// <param name="character">Character on whom proceed encounter</param>
		/// <returns>Encounter succedeed</returns>
		virtual bool proceed(Character^ character) abstract;

		/// <summary>
		/// Interface used for the encounter
		/// </summary>
		property UI::UserInterface^ UserInterface 
		{
			UI::UserInterface^ get();
			void set(UI::UserInterface^ value);
		}
	};
}