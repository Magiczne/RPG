#pragma once

#include "ICharacter.h"

public ref class Warrior
	: ICharacter
{
public:
	Warrior();

	/// <summary>
	/// Gets value of basic melee attack
	/// </summary>
	/// <returns>Damage of basic melee attack</returns>
	virtual int baseMeleeAttack() override;

	/// <summary>
	/// Gets value of basic ranged attack
	/// </summary>
	/// <returns>Value of basic ranged attack</returns>
	virtual int baseRangeAttack() override;

	/// <summary>
	/// Gets value of blocked damage
	/// </summary>
	/// <returns>Value of blocked damage</returns>
	virtual int blockAttack() override;
};