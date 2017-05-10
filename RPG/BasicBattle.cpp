#include "BasicBattle.h"

#include "StatisticsFactory.h"
#include "PlayerDeadException.h"

using namespace Encounters;
using namespace System;
using namespace System::IO;
using namespace System::Collections;
using namespace System::Collections::Generic;

BasicBattle::BasicBattle()
	: Battle()
{
	
}

void BasicBattle::fight(Character^ character)
{
	auto lines = File::ReadAllLines(this->_configFile);

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
			attackPower = attackModifier * character->baseMeleeAttack() - opponentBlockPower;
			chosenOpponent->getStatistics()->substract(StatisticsFactory::onlyHp(attackPower));

			if (chosenOpponent->getStatistics()->HP > 0)
			{
				attackPower = attackModifier * chosenOpponent->baseMeleeAttack() - playerBlockPower;
				character->getStatistics()->substract(StatisticsFactory::onlyHp(attackPower));
			}

			playerBlockPower = 0;
			opponentBlockPower = 0;
			break;
		case 1:		//Ranged attack
			attackPower = attackModifier * character->baseRangeAttack();
			chosenOpponent->getStatistics()->substract(StatisticsFactory::onlyHp(attackPower));

			if (chosenOpponent->getStatistics()->HP > 0)
			{
				attackPower = attackModifier * chosenOpponent->baseRangeAttack();
				character->getStatistics()->substract(StatisticsFactory::onlyHp(attackPower));
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
		if (chosenOpponent->getStatistics()->HP <= 0)
		{
			this->Opponents->Remove(chosenOpponent);
		}
		
		//If there is no more opponents return
		if(Opponents->Count == 0)
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

bool BasicBattle::proceed(Character^ character)
{
	try
	{
		this->fight(character);
		this->Reward->apply(character);
		return false;
	}
	catch(PlayerDeadException^)
	{
		return true;
	}
}