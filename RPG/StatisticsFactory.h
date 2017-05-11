#pragma once

#include "Statistics.h"

public ref class StatisticsFactory
{
public:
	/// <summary>
	/// Returns a new instance of empty statistics object
	/// </summary>
	static property Statistics^ Empty
	{
		Statistics^ get();
	}

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

	/// <summary>
	/// Creates statistics containing only gold
	/// </summary>
	/// <param name="gold"></param>
	/// <returns>Statistics with specified gold</returns>
	static Statistics^ onlyGold(int gold);
};