#pragma once

namespace Achievements
{
	public interface class IAchievementListener
	{
		void achievementUnlocked(System::String^ achievement);
	};
}