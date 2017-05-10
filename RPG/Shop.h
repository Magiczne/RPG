#pragma once

#include "Encounter.h"
#include "Item.h"

namespace Encounters
{
	public ref class Shop abstract
		: public Encounter
	{
	private:
		System::Collections::Generic::List<Items::Item^>^ _items;

	public:
		/// <summary>
		/// Trades with character
		/// </summary>
		/// <param name="character">Character to trade with</param>
		virtual void trade(Character^ character) abstract;

		/// <summary>
		/// Items available in the shop
		///// </summary>
		//property System::Collections::Generic::List<Items::Item^>^ Items
		//{
		//	System::Collections::Generic::List<Items::Item^>^ get();
		//}
	};
}