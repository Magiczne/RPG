#pragma once

#include "Statistics.h"

namespace Items
{
	public ref class IItem abstract
	{
	private:
		System::String^ _name;
		int _price;
		Statistics^ _statistics;

	public:
		/// <summary>
		/// Tells if item it is wearable or not
		/// </summary>
		/// <returns>Item is wearable</returns>
		virtual bool isWearable() abstract;

		/// <summary>
		/// Item name
		/// </summary>
		property System::String^ Name
		{
			System::String^ get();
			void set(System::String^ value);
		}

		/// <summary>
		/// Item Price
		/// </summary>
		property int Price
		{
			int get();
			void set(int value);
		}

		/// <summary>
		/// Gets item statistics
		/// </summary>
		/// <returns>Item statistics</returns>
		property Statistics^ Stats
		{
			Statistics^ get();
			void set(Statistics^ value);
		}
	};
}
