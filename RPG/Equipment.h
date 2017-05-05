#pragma once

#include "Item.h"

public ref class Equipment
{
private:
	int _maxCapacity = 4;
	System::Collections::Generic::List<Items::Item^>^ _toUse;
	System::Collections::Generic::List<Items::Item^>^ _inUse;

public:
	Equipment();

	/// <summary>
	/// Uses item on specified index, or if it is wearable wears it
	/// </summary>
	/// <param name="index">Index of item in _toUse list</param>
	/// <exception cref="ItemNotWearableException"></exception>
	/// <exception cref="EquipmentOutOfRangeException"></exception>
	/// <returns>Statistics of used item</returns>
	Statistics^ use(int index);

	/// <summary>
	/// Wears item on specified index
	/// </summary>
	/// <param name="index">Index of item in the _toUse list</param>
	/// <exception cref="ItemNotWearableException"></exception>
	/// <exception cref="EquipmentOutOfRangeException"></exception>
	/// <returns>Statistics of used item</returns>
	Statistics^ wear(int index);

	/// <summary>
	/// Unwears item from the specified index
	/// </summary>
	/// <param name="index">Index of item in the _inUse list</param>
	/// <exception cref="EquipmentOutOfRangeException"></exception>
	/// <returns>Statistics of used item</returns>
	Statistics^ unWear(int index);

	/// <summary>
	/// Adds item to the _toUse list
	/// </summary>
	/// <param name="item">Specified tem</param>
	void add(Items::Item^ item);

	/// <summary>
	/// Removes item from the _toUse list
	/// </summary>
	/// <param name="item">Specified item</param>
	void remove(Items::Item^ item);
};