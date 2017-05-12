#pragma once

#include "IBattle.h"

namespace Encounters
{
	namespace Factories
	{
		enum BattleType
		{
			Basic,
			WithRetreat
		};

		interface class IBattleFactory
		{
			/// <summary>
			/// Creates a battle of specified type
			/// </summary>
			/// <param name="type">Battle type</param>
			/// <returns>Battle instance</returns>
			IBattle^ create(BattleType type);
		};
	}
}