#pragma once

#include "ICharacter.h"
#include "IEncounter.h"
#include "IItem.h"

namespace Encounters
{
	public ref class IShop abstract
		: public IEncounter
	{
	private:
		System::Collections::Generic::List<Items::IItem^>^ _availableItems;

	public:
		IShop(System::String^ configFile);

		/// <summary>
		/// Trades with character
		/// </summary>
		/// <param name="character">Character to trade with</param>
		virtual void trade(ICharacter^ character) abstract;

		/// <summary>
		/// Items available in the shop
		/// </summary>
		property System::Collections::Generic::List<Items::IItem^>^ AvailableItems 
		{
			System::Collections::Generic::List<Items::IItem^>^ get();
		}
	};
}