#pragma once

#include "BattleWithRetreat.h"
#include "StatisticsFactory.h"

#include "PlayerDeadException.h"
#include "PlayerRetreatException.h"

using namespace Encounters;

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

BattleWithRetreat::BattleWithRetreat(String^ configFile)
	: IBattle(configFile)
{
	
}

void BattleWithRetreat::fight(ICharacter^ character)
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

		for each(auto opponent in Opponents)
		{
			opponentList->Add(opponent->Description);
		}

		auto opponentNumber = this->UserInterface->askQuestion(chooseOpponentQuestion, opponentList);
		auto chosenOpponent = Opponents[opponentNumber];

		//Fighting
		auto actionAnswer = this->UserInterface->askQuestion(actionQuestion, actionAnswers);

		switch (actionAnswer)
		{
		case 0:		//Melee attack
			attackPower = safe_cast<int>(attackModifier * character->baseMeleeAttack() - opponentBlockPower);
			chosenOpponent->getStatistics()->substract(StatisticsFactory::onlyHp(attackPower));

			if (chosenOpponent->getStatistics()->HP > 0)
			{
				attackPower = safe_cast<int>(attackModifier * chosenOpponent->baseMeleeAttack() - playerBlockPower);
				character->getStatistics()->substract(StatisticsFactory::onlyHp(attackPower));
			}

			playerBlockPower = 0;
			opponentBlockPower = 0;
			break;
		case 1:		//Ranged attack
			attackPower = safe_cast<int>(attackModifier * character->baseRangeAttack());
			chosenOpponent->getStatistics()->substract(StatisticsFactory::onlyHp(attackPower));

			if (chosenOpponent->getStatistics()->HP > 0)
			{
				attackPower = safe_cast<int>(attackModifier * chosenOpponent->baseRangeAttack());
				character->getStatistics()->substract(StatisticsFactory::onlyHp(attackPower));
			}

			playerBlockPower = 0;
			opponentBlockPower = 0;
			break;
		case 2:		//Block
			playerBlockPower = character->baseMeleeAttack();
			opponentBlockPower = chosenOpponent->blockAttack();
			break;
		case 3:		//Retreat
			throw gcnew PlayerRetreatException;
			return;
		default:	//Just break
			break;
		}

		//If opponent dead remove
		if (chosenOpponent->getStatistics()->HP <= 0)
		{
			this->Opponents->Remove(chosenOpponent);
		}

		//If there is no more opponents return
		if (Opponents->Count == 0)
		{
			return;
		}

		//If player dead return and throw
		if (character->getStatistics()->HP <= 0)
		{
			throw gcnew PlayerDeadException;
			return;
		}
	}
}

bool BattleWithRetreat::proceed(ICharacter^ character)
{
	try
	{
		return IBattle::proceed(character);
	}
	catch(PlayerRetreatException^)
	{
		return false;
	}
}