#include "AskQuestion.h"

using namespace RPG;

AskQuestion::AskQuestion(String^ question, List<String^>^ answers)
{
	InitializeComponent();

	this->label1->Text = question;

	for each (auto answer in answers)
	{
		this->listBox1->Items->Add(answer);
	}

	this->listBox1->SelectedIndex = 0;
}

AskQuestion::~AskQuestion()
{
	if (components)
	{
		delete components;
	}
}

int AskQuestion::SelectedAnswer::get()
{
	return this->listBox1->SelectedIndex;
}

Void AskQuestion::button1_Click(Object^  sender, EventArgs^  e)
{
	this->Close();
}