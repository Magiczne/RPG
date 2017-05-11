#pragma once

#include "Statistics.h"

public ref class StatisticsFactory
{
public:
	/// <summary>
	/// Creates statistics containing only mana points
	/// </summary>
	/// <param name="mana"></param>
	/// <returns>Statistics with specified mana</returns>
	static Statistics^ onlyMana(int mana);

	/// <summary>
	/// Creates statistics containing only health points
	/// </summary>
	/// <param name="mana"></param>
	/// <returns>Statistics with specified health</returns>
	static Statistics^ onlyHp(int mana);
};