#pragma once

#include "IShop.h"
#include "IItem.h"

namespace Encounters
{
	public ref class Shop 
		: public IShop
	{
	private:
		Items::IItem^ _selectedItem;
		array<System::String^>^ _data;

	public:
		Shop(System::String^ configFile);

		/// <summary>
		/// Trades with character
		/// </summary>
		/// <param name="character">Character to trade with</param>
		virtual void trade(ICharacter^ character) override;

		/// <summary>
		/// Process an encounter on player
		/// </summary>
		/// <param name="character">Character on whom encounter was proceeded</param>
		/// <returns>Encounter succedeed</returns>
		virtual bool proceed(ICharacter^ character) override;

		/// <summary>
		/// Selected Item
		/// </summary>
		property Items::IItem^ SelectedItem
		{
			Items::IItem^ get();
			void set(Items::IItem^ value);
		}
	};
}