#pragma once

#include "IGame.h"
#include "ILocation.h"
#include "IEncounter.h"

public ref class Game
	: public IGame
{
private:

public:
	/// <summary>
	/// Creates a game with specified number of location
	/// </summary>
	/// <param name="locations">Number of location</param>
	/// <returns>Created map</returns>
	virtual IMap^ createGame(int locations) override;

	/// <summary>
	/// Starts game
	/// </summary>
	virtual void start() override;

	/// <summary>
	/// Creates random location
	/// </summary>
	Locations::ILocation^ createLocation();

	/// <summary>
	/// Creates random specified encounter
	/// </summary>
	Encounters::IEncounter^ createEncounter();
};
