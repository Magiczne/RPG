#pragma once

#include "IBattleFactory.h"

namespace Encounters
{
	namespace Factories
	{
		public ref class BattleFactory
			: IBattleFactory
		{
		public:

			/// <summary>
			/// Creates a battle of specified type
			/// </summary>
			/// <param name="type">Battle type</param>
			/// <returns>Battle instance</returns>
			virtual IBattle^ create(BattleType type);
		};
	}
}