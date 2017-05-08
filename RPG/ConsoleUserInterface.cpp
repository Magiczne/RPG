#include "ConsoleUserInterface.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace UI;

int ConsoleUserInterface::askQuestion(String^ question, List<String^>^ answers)
{
	this->writeCentered(question);

	for(int i = 0; i < answers->Count; i++)
	{
		this->writeCentered(i.ToString() + ". " + answers[i]);
	}

	int choice;

	do
	{
		choice = Console::Read();
	} while (choice > answers->Count - 1);

	return choice;
}

void ConsoleUserInterface::showMessage(String^ message)
{
	this->writeCentered(message);
}

void ConsoleUserInterface::writeCentered(String^ message)
{
	Console::WriteLine(
		String::Format(
			"{0," + ((Console::WindowWidth / 2) + (message->Length / 2)) + "}",
			message
		)
	);
}