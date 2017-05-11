#pragma once

#include "IReward.h"
#include "Statistics.h"

namespace Encounters
{
	namespace Rewards
	{
		public ref class GoldReward
			: public IReward
		{
		private:
			Statistics^ _stats;

		public:
			GoldReward();

			/// <summary>
			/// Applies reward to specified character
			/// </summary>
			/// <param name="character">Character that we want to apply reward for</param>
			virtual void apply(ICharacter^ character);

			/// <summary>
			/// Adds gold to the reward
			/// </summary>
			/// <param name="amount">Amount of gold to be added</param>
			void addGold(int amount);
		};
	}
}