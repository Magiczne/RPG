#include "BattleFactory.h"

#include "BasicBattle.h"
#include "BattleWithRetreat.h"

#include "GiantWaspFactory.h"
#include "MysteriousWizardFactory.h"
#include "OrcFactory.h"

#include "GoldReward.h"
#include "ItemReward.h"
#include "TitleReward.h"

#include "Apple.h"

#include "ConsoleUserInterface.h"

using namespace Encounters;
using namespace Encounters::Factories;
using namespace Encounters::Rewards;
using namespace Items;
using namespace UI;

using namespace System;
using namespace System::IO;

IBattle^ BattleFactory::create(BattleType type)
{
	IBattle^ battle;

	switch(type)
	{
	case BattleType::Basic:
		battle = gcnew BasicBattle(Path::Combine("ConfigFiles", "BasicBattle.txt"));
		break;

	case BattleType::WithRetreat:
		battle = gcnew BasicBattle(Path::Combine("ConfigFiles", "BattleWithRetreat.txt"));
		break;
	}

	battle->UserInterface = ConsoleUserInterface::Instance;

	auto random = gcnew Random();

	for(int i = 0; i < random->Next(1, 3); i++)
	{
		ICharacter^ character;
		switch (random->Next(0, 2))
		{
		case 0:
			character = (gcnew GiantWaspFactory)->createCharacter();
			break;
		case 1:
			character = (gcnew MysteriousWizardFactory)->createCharacter();
			break;
		case 2:
			character = (gcnew OrcFactory)->createCharacter();
			break;
		default:
			throw gcnew ArgumentOutOfRangeException("random->Next(0, 2)");
		}

		battle->Opponents->Add(safe_cast<IOpponent^>(character));
	}

	IReward^ reward;

	switch(random->Next(0, 2))
	{
	case 0:
		reward = gcnew GoldReward();
		(safe_cast<GoldReward^>(reward))->addGold(random->Next(10, 20));
		break;
	case 1:
		reward = gcnew ItemReward();
		(safe_cast<ItemReward^>(reward))->addItem(gcnew Apple());
		break;
	case 2:
		reward = gcnew TitleReward("Great great");
		break;
	}

	battle->Reward = reward;

	return battle;
}