#pragma once

#include "Character.h"

namespace Encounters
{
	namespace Rewards
	{
		public interface class Reward
		{
			/// <summary>
			/// Applies reward to specified character
			/// </summary>
			/// <param name="character">Character that we want to apply reward for</param>
			void apply(Character^ character);
		};
	}
}