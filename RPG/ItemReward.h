#pragma once

#include "IReward.h"
#include "IItem.h"

namespace Encounters
{
	namespace Rewards
	{
		public ref class ItemReward
			: public IReward
		{
		private:
			System::Collections::Generic::List<Items::IItem^>^ _items;

		public:
			ItemReward();

			/// <summary>
			/// Applies reward to specified character
			/// </summary>
			/// <param name="character">Character that we want to apply reward for</param>
			virtual void apply(ICharacter^ character);

			/// <summary>
			/// Adds item to the reward
			/// </summary>
			/// <param name="item">Item to add</param>
			void addItem(Items::IItem^ item);
		};
	}
}