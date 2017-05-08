#pragma once

#include "UserInterface.h"

namespace UI
{
	public ref class ConsoleUserInterface 
		: public UserInterface
	{
	public:
		/// <summary>
		/// Asks the user a question with answers and gets the answer from him
		/// </summary>
		/// <param name="question">Question to ask</param>
		/// <param name="answers">Answers for the question</param>
		/// <returns>Chosen answer numer</returns>
		virtual int askQuestion(System::String^ question, System::Collections::Generic::List<System::String^>^ answers) override;

		/// <summary>
		/// Shows message for the user in the console window
		/// </summary>
		/// <param name="message"></param>
		virtual void showMessage(System::String^ message) override;

	private:

		/// <summary>
		/// Writes text centered
		/// </summary>
		/// <param name="message"></param>
		void writeCentered(System::String^ message);
	};
}