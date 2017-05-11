#pragma once

#include "ICharacter.h"

namespace Encounters
{
	namespace Rewards
	{
		public interface class IReward
		{
			/// <summary>
			/// Applies reward to specified character
			/// </summary>
			/// <param name="character">Character that we want to apply reward for</param>
			void apply(ICharacter^ character);
		};
	}
}