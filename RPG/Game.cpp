#include "Game.h"

#include "BasicBattle.h"
#include "BattleWithRetreat.h"
#include "Location.h"
#include "Map.h"
#include "Shop.h"
#include "Warrior.h"

#include "ShopFactory.h"
#include "BattleFactory.h"

using namespace Encounters;
using namespace Encounters::Factories;
using namespace Locations;

using namespace System;
using namespace System::Collections::Generic;

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
		map->LocationsList->Add(this->createLocation());

		//Create adjacency list for current vertex of the graph
		auto adjacency = gcnew List<int>();

		//Currently generating all connections to the neighbour location
		for(int j = 0; j < neighbourIndexModifiers->Length; j++)
		{
			auto index = i + neighbourIndexModifiers[j];

			if(index < 0 || index % inLine == 0 || index >= locations)
			{
				continue;
			}

			adjacency->Add(index);
		}

		//Add adjacency list for current vertex to the map
		map->LocationsAdjacency->Add(adjacency);
	}

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
	auto location = gcnew Location("Location.txt");

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