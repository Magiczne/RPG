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

void BasicBattle::fight(Character^ characater)
{
	auto lines = File::ReadAllLines(this->_configFile);

	auto answers = gcnew List<String^>();

	String^ question = lines[2];
	for (int i = 3; i < lines->Length; i++)
	{
		answers->Add(lines[i]);
	}

	auto random = gcnew Random();

	for each(auto currentOpponent in this->Opponents)
	{
		double attackModifier = (double)random->Next(75, 100) / 100.0;

		int attackPower = 0;
		int playerBlockPower = 0;
		int opponentBlockPower = 0;

		while (true)
		{
			auto answer = this->UserInterface->askQuestion(question, answers);

			switch (answer)
			{
			case 0:		//Melee attack
				attackPower = attackModifier * characater->baseMeleeAttack() - opponentBlockPower;
				currentOpponent->getStatistics()->substract(StatisticsFactory::onlyHp(attackPower));

				if (currentOpponent->getStatistics()->HP > 0)
				{
					attackPower = attackModifier * currentOpponent->baseMeleeAttack() - playerBlockPower;
					characater->getStatistics()->substract(StatisticsFactory::onlyHp(attackPower));
				}

				playerBlockPower = 0;
				opponentBlockPower = 0;
				break;
			case 1:		//Ranged attack
				attackPower = attackModifier * characater->baseRangeAttack();
				currentOpponent->getStatistics()->substract(StatisticsFactory::onlyHp(attackPower));

				if (currentOpponent->getStatistics()->HP > 0)
				{
					attackPower = attackModifier * currentOpponent->baseRangeAttack();
					characater->getStatistics()->substract(StatisticsFactory::onlyHp(attackPower));
				}

				playerBlockPower = 0;
				opponentBlockPower = 0;
				break;
			case 2:		//Block
				playerBlockPower = characater->baseMeleeAttack();
				opponentBlockPower = currentOpponent->blockAttack();
				break;
			default:	//Just break
				break;
			}

			//If opponent dead remove
			if (currentOpponent->getStatistics()->HP <= 0)
			{
				this->Opponents->Remove(currentOpponent);
			}

			//If player dead return and throw
			if(characater->getStatistics()->HP <= 0)
			{
				throw gcnew PlayerDeadException;
				return;
			}
		}
	}
}

bool BasicBattle::proceed(Character^ character)
{
	try
	{
		this->fight(character);
		return false;
	}
	catch(PlayerDeadException^)
	{
		return true;
	}
}