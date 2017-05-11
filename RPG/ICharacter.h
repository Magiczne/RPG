#pragma once

#include "Equipment.h"
#include "Statistics.h"

public ref class ICharacter abstract
{
protected:
	System::String^ _description;
	Statistics^ _statistics;
	Equipment^ _equipment;

public: 
	ICharacter(Statistics^ stats);

	/// <summary>
	/// Character description
	/// </summary>
	property System::String^ Description {
		System::String^ get();
		protected: void set(System::String^ value);
	}
	
	/// <summary>
	/// Gets maximum Health Points
	/// </summary>
	/// <returns>Maximum health points</returns>
	int getMaxHp();

	/// <summary>
	/// Gets maximum Mana Points
	/// </summary>
	/// <returns>Maximum Mana Points</returns>
	int getMaxMana();

	/// <summary>
	/// Gets value of basic melee attack
	/// </summary>
	/// <returns>Value of basic melee attack</returns>
	virtual int baseMeleeAttack() abstract;

	/// <summary>
	/// Gets value of basic ranged attack
	/// </summary>
	/// <returns>Value of basic ranged attack</returns>
	virtual int baseRangeAttack() abstract;

	/// <summary>
	/// Gets value of blocked damage
	/// </summary>
	/// <returns>Value of blocked damage</returns>
	virtual int blockAttack() abstract;

	/// <summary>
	/// Uses item on specified index or if it is wearable wears it
	/// </summary>
	/// <param name="index">Index of item in toUse list in equipment</param>
	void use(int index);

	/// <summary>
	/// Wears item on specified index.
	/// If item has been worn returns true, else return false.
	/// Returns false when index is out of equipment range.
	/// </summary>
	/// <param name="index">Index of item in toUse list in equipment</param>
	/// <returns>Item has been worn</returns>
	bool wear(int index);

	/// <summary>
	/// Takes off item on specified index.
	/// If item has been taken off returns true, else returns false.
	/// Returns false when index is out of equipment range.
	/// </summary>
	/// <param name="index">Index of item in inUse list in equipment</param>
	/// <returns>Item has been taken off</returns>
	bool unWear(int index);

	/// <summary>
	/// Gets character statistics
	/// </summary>
	/// <returns>Character statistics</returns>
	Statistics^ getStatistics();
};
