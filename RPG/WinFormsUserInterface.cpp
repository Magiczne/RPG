#include "WinFormsUserInterface.h"
#include "AskQuestion.h"

using namespace UI;

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

WinFormsUserInterface::WinFormsUserInterface() {}

WinFormsUserInterface::WinFormsUserInterface(const WinFormsUserInterface%)
{
	throw gcnew InvalidOperationException("Singleton cannot be coppied");
}

WinFormsUserInterface^ WinFormsUserInterface::Instance::get()
{
	return %WinFormsUserInterface::_instance;
}

void WinFormsUserInterface::showMessage(String^ message)
{
	MessageBox::Show("Message", message);
}

void WinFormsUserInterface::achievementUnlocked(String^ achievement)
{
	MessageBox::Show("Achievement unlocked", achievement);
}

int WinFormsUserInterface::askQuestion(String^ question, List<String^>^ answers)
{
	auto form = gcnew RPG::AskQuestion(question, answers);

	form->ShowDialog();

	return form->SelectedAnswer;
}