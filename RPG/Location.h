#pragma once

#include "ICharacter.h"
#include "ILocation.h"

namespace Locations
{
	public ref class Location
		: public ILocation
	{
	private:
		array<System::String^>^ _data;

	public:
		Location(System::String^ configFile);

		/// <summary>
		/// Starts plot of the location
		/// </summary>
		virtual ILocation^ run(ICharacter^ character) override;
	};
}