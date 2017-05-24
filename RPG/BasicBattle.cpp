#include "BasicBattle.h"

#include "StatisticsFactory.h"
#include "PlayerDeadException.h"
#include "KillCountManager.h"

using namespace Achievements;
using namespace Encounters;

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

BasicBattle::BasicBattle(String^ configFile)
	: IBattle(configFile)
{
	
}

void BasicBattle::fight(ICharacter^ character)
{
	auto lines = File::ReadAllLines(this->ConfigFile);

	auto actionAnswers = gcnew List<String^>();

	String^ actionQuestion = lines[2];
	String^ chooseOpponentQuestion = lines[3];
	for (int i = 4; i < lines->Length; i++)
	{
		actionAnswers->Add(lines[i]);
	}

	auto random = gcnew Random();

	double attackModifier = (double)random->Next(75, 100) / 100.0;

	int attackPower = 0;
	int playerBlockPower = 0;
	int opponentBlockPower = 0;

	while (true)
	{
		//Chosing opponent
		auto opponentList = gcnew List<String^>();

		for each(auto opponent in this->Opponents)
		{
			opponentList->Add(opponent->Description);
		}

		auto opponentNumber = this->UserInterface->askQuestion(chooseOpponentQuestion, opponentList);
		auto chosenOpponent = this->Opponents[opponentNumber];
		
		//Fighting
		auto actionAnswer = this->UserInterface->askQuestion(actionQuestion, actionAnswers);

		switch (actionAnswer)
		{
		case 0:		//Melee attack
			attackPower = safe_cast<int>(attackModifier * character->baseMeleeAttack() - opponentBlockPower);
			chosenOpponent->Stats->substract(StatisticsFactory::onlyHp(attackPower));

			if (chosenOpponent->Stats->HP > 0)
			{
				attackPower = safe_cast<int>(attackModifier * chosenOpponent->baseMeleeAttack() - playerBlockPower);
				character->Stats->substract(StatisticsFactory::onlyHp(attackPower));
			}

			playerBlockPower = 0;
			opponentBlockPower = 0;
			break;
		case 1:		//Ranged attack
			attackPower = safe_cast<int>(attackModifier * character->baseRangeAttack());
			chosenOpponent->Stats->substract(StatisticsFactory::onlyHp(attackPower));

			if (chosenOpponent->Stats->HP > 0)
			{
				attackPower = safe_cast<int>(attackModifier * chosenOpponent->baseRangeAttack());
				character->Stats->substract(StatisticsFactory::onlyHp(attackPower));
			}

			playerBlockPower = 0;
			opponentBlockPower = 0;
			break;
		case 2:		//Block
			playerBlockPower = character->baseMeleeAttack();
			opponentBlockPower = chosenOpponent->blockAttack();
			break;
		default:	//Just break
			break;
		}

		//If opponent dead remove
		if (chosenOpponent->Stats->HP <= 0)
		{
			this->Opponents->Remove(chosenOpponent);
			KillCountManager::Instance->addKills(1);
		}
		
		//If there is no more opponents return
		if(Opponents->Count == 0)
		{
			return;
		}

		//If player dead return and throw
		if (character->Stats->HP <= 0)
		{
			throw gcnew PlayerDeadException;
			return;
		}
	}
}