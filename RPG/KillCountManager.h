#pragma once

#include "IAchievementManager.h"

namespace Achievements
{
	public ref class KillCountManager
		: public IAchievementManager
	{
	private:
		static KillCountManager _instance;

		int _kills;

		KillCountManager();
		KillCountManager(const KillCountManager%);

	protected:
		virtual void notifyAll() override;

	public:
		static property KillCountManager^ Instance
		{
			KillCountManager^ get();
		}

		property int Kills 
		{
			int get();
			void set(int value);
		}

		void addKills(int kills);
	};
}