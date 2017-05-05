#pragma once

#include "Encounter.h"

namespace Locations
{
	public ref class Location abstract
	{
	private:
		System::String^ _name;
		System::String^ _description;
		System::String^ _configFile;
		System::Collections::Generic::List<Encounters::Encounter^>^ _encounters;

	public:

		/// <summary>
		/// Starts plot of the location
		/// </summary>
		virtual void run() abstract;

		/// <summary>
		/// Name of the location
		/// </summary>
		property System::String^ Name 
		{
			System::String^ get();
			void set(System::String^ value);
		}

		/// <summary>
		/// Description of the location
		/// </summary>
		property System::String^ Description
		{
			System::String^ get();
			void set(System::String^ value);
		}

		/// <summary>
		/// Encounters in the location
		/// </summary>
		property System::Collections::Generic::List<Encounters::Encounter^>^ Encounters
		{
			System::Collections::Generic::List<Encounters::Encounter^>^ get();
		}
	};
}