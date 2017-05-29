
#include "Battle1.h"
#include "ConsoleUserInterface.h"

//#include "NameReward.h"

#include "OrcFactory.h"
#include "StatisticsFactory.h"
#include "TitleReward.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

using namespace Encounters;

Battle1::Battle1()
	: IBattle("Battle1.txt")
{
	//this->data = System::IO::File::ReadAllLines();
	//this->opponents = gcnew List<Character^>();
}
void Battle1::fight(ICharacter^ character)
{
	auto cf = gcnew OrcFactory();
	for (int i = 0; i<3; i++)
	{
		auto opponent = cf->createCharacter();
		this->Opponents->Add(safe_cast<IOpponent^>(opponent));
	}
	List<String^>^ answers = gcnew List<String^>();
	int counter = 0;
	int choose = 0;

	auto ui = this->UserInterface;
	//UI::IUserInterface^ ui = gcnew ConsoleUserInterface();

	ui->showMessage(data[0]);
	int round = 1;
	ui->showMessage("1. " + data[3]);
	ui->showMessage("2. " + data[4]);
	ui->showMessage("3. " + data[5]);
	for each(auto opponent in Opponents)
	{
		Random^ rand = gcnew Random();
		round++;
		int random_strength = rand->Next(1, round);
		int random_distance = rand->Next(1, 2);

		ui->showMessage(opponent->Description);
		int attack = opponent->baseMeleeAttack();
		String^ question = data[2];

		answers->Add(this->data[3]);
		answers->Add(this->data[4]);
		answers->Add(this->data[5]);
		do
		{

			choose = ui->askQuestion(question, answers);

			if (choose != 1 && choose != 2 && choose != 3 && choose != 4)
			{
				ui->showMessage(data[6]);
			}
		} while (choose != 1 && choose != 2 && choose != 3 && choose != 4);

		answers->Clear();
		if (choose == 1)
		{
			if (random_distance == 1)
			{
				opponent->Stats->substract(StatisticsFactory::onlyHp(character->baseMeleeAttack() - random_strength));
				character->Stats->substract(StatisticsFactory::onlyHp(opponent->baseMeleeAttack() - random_strength));
				//opponent->Stats->HP -= character->baseMeleeAttack() - random_strength;
				//character->Stats->HP -= opponent->baseMeleeAttack() - random_strength;
			}
			else
			{
				opponent->Stats->substract(StatisticsFactory::onlyHp(character->baseMeleeAttack() - random_strength - 1));
				character->Stats->substract(StatisticsFactory::onlyHp(opponent->baseMeleeAttack() - random_strength - 1));
				/*opponent->Stats->HP -= character->baseMeleeAttack() - random_strength - 1;
				character->Stats->HP -= opponent->baseMeleeAttack() - random_strength - 1;*/
			}
			ui->showMessage(data[7]);
		}
		else if (choose == 2)
		{
			if (random_distance == 1)
			{
				opponent->Stats->substract(StatisticsFactory::onlyHp(character->baseRangeAttack() - random_strength));
				character->Stats->substract(StatisticsFactory::onlyHp(opponent->baseRangeAttack() - random_strength));
				/*opponent->Stats->HP -= -character->baseRangeAttack() - random_strength;
				character->Stats->HP -= opponent->baseMeleeAttack() - random_strength;*/
			}
			else
			{
				opponent->Stats->substract(StatisticsFactory::onlyHp(character->baseRangeAttack() - random_strength - 1));
				character->Stats->substract(StatisticsFactory::onlyHp(opponent->baseRangeAttack() - random_strength - 1));
		/*		opponent->Stats->HP -= -character->baseRangeAttack() - random_strength - 1;
				character->Stats->HP -= opponent->baseMeleeAttack() - random_strength - 1;*/
			}
			ui->showMessage(data[7]);
		}
		else if (choose == 3)
		{
			if (random_distance == 1)
			{
				character->Stats->substract(StatisticsFactory::onlyHp(character->baseMeleeAttack() - 3 - random_strength));
				//character->Stats->HP -= opponent->baseMeleeAttack() - 3 - random_strength;
			}
			else
			{
				character->Stats->substract(StatisticsFactory::onlyHp(character->baseMeleeAttack() - 4 - random_strength));
				//character->Stats->HP -= opponent->baseMeleeAttack() - 4 - random_strength;
			}
			ui->showMessage(data[7]);
		}
		if (choose == 4)
		{
			ui->showMessage(data[7]);
		}

		if (opponent->Stats->HP <= 0 && character->Stats->HP>0)
		{
			counter++;
			ui->showMessage(data[8]);
		}
		if (character->Stats->HP <= 0)
		{
			ui->showMessage(data[9]);
			break;
		}
	}
	ui->showMessage(data[7]);
	if (counter == Opponents->Count)
	{
		ui->showMessage(data[10]);
		
		this->Reward = gcnew Rewards::TitleReward("Title");
		Reward->apply(character);
	}

}
bool Battle1::proceed(ICharacter^ character)
{
	if (character->Stats->HP <= 0)
	{
		return false;
	}
	else
	{
		this->fight(character);
		return true;
	}
}