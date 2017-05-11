#pragma once

#include "ICharacter.h"

public ref class ICharacterDecorator abstract
	: public ICharacter
{
private:
	ICharacter^ _character;
	System::String^ _title;

public:
	ICharacterDecorator(ICharacter^ character);

	/// <summary>
	/// Character descriptin
	/// </summary>
	property System::String^ Description
	{
		virtual System::String^ get() override;
	}

	/// <summary>
	/// Character statistics
	/// </summary>
	/// <returns>Character statistics</returns>
	virtual property Statistics^ Stats
	{
		Statistics^ get() override;
	}

	/// <summary>
	/// Character equipment
	/// </summary>
	virtual property Equipment^ Eq
	{
		Equipment^ get() override;
	}

	/// <summary>
	/// Maximum Health Points
	/// </summary>
	/// <returns>Maximum health points</returns>
	virtual property int MaxHp
	{
		int get() override;
	}

	/// <summary>
	/// Gets maximum Mana Points
	/// </summary>
	/// <returns>Maximum Mana Points</returns>
	virtual property int MaxMana
	{
		int get() override;
	}

	/// <summary>
	/// Gets value of basic melee attack
	/// </summary>
	/// <returns>Value of basic melee attack</returns>
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

	/// <summary>
	/// Uses item on specified index or if it is wearable wears it
	/// </summary>
	/// <param name="index">Index of item in toUse list in equipment</param>
	virtual void use(int index) override;

	/// <summary>
	/// Wears item on specified index.
	/// If item has been worn returns true, else return false.
	/// Returns false when index is out of equipment range.
	/// </summary>
	/// <param name="index">Index of item in toUse list in equipment</param>
	/// <returns>Item has been worn</returns>
	virtual bool wear(int index) override;

	/// <summary>
	/// Takes off item on specified index.
	/// If item has been taken off returns true, else returns false.
	/// Returns false when index is out of equipment range.
	/// </summary>
	/// <param name="index">Index of item in inUse list in equipment</param>
	/// <returns>Item has been taken off</returns>
	virtual bool unWear(int index) override;
};