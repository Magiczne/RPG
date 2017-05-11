#pragma once

#include "IEncounter.h"
#include "ICharacter.h"

namespace Locations
{
	public ref class ILocation abstract
	{
	private:
		System::String^ _name;
		System::String^ _description;
		System::String^ _configFile;
		System::Collections::Generic::List<Encounters::IEncounter^>^ _encounters;
		System::Collections::Generic::List<ILocation^>^ _neighbourLocations;

	public:

		/// <summary>
		/// Starts plot of the location
		/// </summary>
		virtual ILocation^ run(ICharacter^ character) abstract;

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
		property System::Collections::Generic::List<Encounters::IEncounter^>^ Encounters
		{
			System::Collections::Generic::List<Encounters::IEncounter^>^ get();
		}

		/// <summary>
		/// Neighbour locations
		/// </summary>
		property System::Collections::Generic::List<ILocation^>^ NeighbourLocations
		{
			System::Collections::Generic::List<ILocation^>^ get();
		}
	};
}