#include "Game.h"

#include "BasicBattle.h"
#include "BattleWithRetreat.h"
#include "Location.h"
#include "Map.h"
#include "Shop.h"
#include "Warrior.h"

#include "ShopFactory.h"
#include "BattleFactory.h"

#include "ConsoleUserInterface.h"

using namespace Encounters;
using namespace Encounters::Factories;
using namespace Locations;
using namespace UI;

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

Game::Game()
{
	this->UserInterface = ConsoleUserInterface::Instance;
}

IMap^ Game::createGame(int locations)
{
	auto map = gcnew Map();

	int maxEdges = 4;	//N W S E

	//Try to achieve that number of locations in line
	int inLine = safe_cast<int>(Math::Round(Math::Sqrt(locations)));

	//Numers to add to base index to get all neighbours[Left, Top, Right, Bottom]
	array<int>^ neighbourIndexModifiers = gcnew array<int> { -1, -inLine, 1, inLine };

	for(int i = 0; i < locations; i++)
	{
		auto location = this->createLocation();

		//Create adjacency list for current vertex of the graph
		auto adjacency = gcnew List<int>();

		//Currently generating all connections to the neighbour location
		for(int j = 0; j < neighbourIndexModifiers->Length; j++)
		{
			auto index = i + neighbourIndexModifiers[j];

			if(index < 0 || index % inLine == 0 || (index >= locations && i % inLine == 2))
			{
				continue;
			}

			adjacency->Add(index);
		}

		//Add location to locations list
		map->LocationsList->Add(location);

		//Add adjacency list for current vertex to the map
		map->LocationsAdjacency->Add(adjacency);
	}

	//Tell all locations theirs neighbours
	for(int i = 0; i < map->LocationsAdjacency->Count; i++)
	{
		for each(auto index in map->LocationsAdjacency[i])
		{
			map->LocationsList[i]->NeighbourLocations->Add(map->LocationsList[index]);
		}
	}

	//Setup starting location
	map->StartLocation = map->LocationsList[0];

	return map;
}

void Game::start()
{
	auto player = gcnew Warrior();

	auto map = this->createGame(9);

	map->run(player);
}

ILocation^ Game::createLocation()
{
	auto location = gcnew Location(Path::Combine("ConfigFiles", "Location.txt"));
	location->UserInterface = this->UserInterface;

	auto random = gcnew Random();

	for(int i = 0; i < random->Next(1, 2); i++)
	{
		auto encounter = this->createEncounter();
		
		location->AvailableEncounters->Add(encounter);
	}

	return location;
}

IEncounter^ Game::createEncounter()
{
	auto random = gcnew Random();
	IEncounter^ encounter;

	int choice = random->Next(0, 2);

	switch(choice)
	{
	case 0:		//Shop
		encounter = (gcnew ShopFactory)->create(
			random->Next(0, 1)
			? ShopType::Groceries
			: ShopType::EqiupmentShop
		);
		break;
	case 1:		//Basic battle
		encounter = (gcnew BattleFactory)->create(BattleType::Basic);
		break;
	case 2:		//Battle with retreat
		encounter = (gcnew BattleFactory)->create(BattleType::WithRetreat);
		break;
	default:
		break;
	}

	return encounter;
}