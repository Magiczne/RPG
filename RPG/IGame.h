#pragma once

#include "IMap.h"
#include "IUserInterface.h"

public ref class IGame abstract
{
private:
	UI::IUserInterface^ _userInterface;

public:
	/// <summary>
	/// Creates a game with specified number of location
	/// </summary>
	/// <param name="locations">Number of location</param>
	/// <returns>Created map</returns>
	virtual IMap^ createGame(int locations) abstract;


	/// <summary>
	/// User interface
	/// </summary>
	property UI::IUserInterface^ UserInterface
	{
		UI::IUserInterface^ get();
	}
};