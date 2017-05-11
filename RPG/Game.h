#pragma once

#include "IGame.h"

public ref class Game
	: public IGame
{
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
};
