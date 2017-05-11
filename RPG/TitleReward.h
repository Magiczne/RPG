#pragma once

#include "IReward.h"

namespace Encounters
{
	namespace Rewards
	{
		public ref class TitleReward
			: public IReward
		{
		private:
			System::String^ _title;

		public:
			TitleReward(System::String^ title);

			/// <summary>
			/// Applies reward to specified character
			/// </summary>
			/// <param name="character">Character that we want to apply reward for</param>
			virtual void apply(ICharacter^ character);
		};
	}
}