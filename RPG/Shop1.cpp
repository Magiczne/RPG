#include "Shop1.h"
#include "ConsoleUserInterface.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

Shop1::Shop1(String^ conf) 
	: IShop(conf)
{
	/*this->ConfigFile = conf;*/
	this->data = System::IO::File::ReadAllLines(this->ConfigFile);
}
void Shop1::trade(ICharacter^ character)
{
	//UserInterface^ ui = gcnew ConsoleUserInterface();
	auto ui = this->UserInterface;

	if (character->Stats->Gold >= selectedItem->Price)
	{
		character->Eq->add(selectedItem);
		character->Stats->add(selectedItem->Stats);
		character->Stats->substract(gcnew Statistics(0, 0, 0, 0, 0, 0, 0, selectedItem->Price));
	}
	else
	{
		ui->showMessage(data[0]);
	}
	selectedItem = nullptr;
}
bool Shop1::proceed(ICharacter^ character)
{
	auto question = this->data[1];

	List<String^>^ answers = gcnew List<String^>();

	for (;;)
	{
		answers->Clear();
		for each(auto item in this->AvailableItems)
		{
			answers->Add(item->Name);
		}
		answers->Add(this->data[2]);

		auto choice = this->UserInterface->askQuestion(question, answers);

		if (choice == answers->Count - 1)
		{
			return true;
		}
		else
		{
			this->selectedItem = this->AvailableItems[choice];
			this->trade(character);
		}
	}
}