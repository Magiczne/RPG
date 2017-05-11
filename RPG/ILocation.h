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
		System::Collections::Generic::List<Encounters::IEncounter^>^ _availableEncounters;
		System::Collections::Generic::List<ILocation^>^ _neighbourLocations;

	public:
		ILocation(System::String^ configFile);

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
		/// Config file of the location
		/// </summary>
		property System::String^ ConfigFile
		{
			System::String^ get();
		}

		/// <summary>
		/// Encounters in the location
		/// </summary>
		property System::Collections::Generic::List<Encounters::IEncounter^>^ AvailableEncounters
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