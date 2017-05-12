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

	public:
		Shop(System::String^ configFile);

		/// <summary>
		/// Trades with character
		/// </summary>
		/// <param name="character">Character to trade with</param>
		virtual void trade(ICharacter^ character) override;

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