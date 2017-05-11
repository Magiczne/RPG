#pragma once

#include "IUserInterface.h"

namespace UI
{
	public ref class ConsoleUserInterface 
		: public IUserInterface
	{
	public:
		/// <summary>
		/// Asks the user a question with answers and gets the answer from user
		/// </summary>
		/// <param name="question">Question to ask</param>
		/// <param name="answers">Answers for the question</param>
		/// <returns>Chosen answer numer</returns>
		virtual int askQuestion(System::String^ question, System::Collections::Generic::List<System::String^>^ answers);

		/// <summary>
		/// Shows message for the user in the console window
		/// </summary>
		/// <param name="message"></param>
		virtual void showMessage(System::String^ message);

		/// <summary>
		/// Instance of the Interface
		/// </summary>
		static property ConsoleUserInterface^ Instance 
		{
			ConsoleUserInterface^ get();
		}

	private:
		static ConsoleUserInterface _instance;

		ConsoleUserInterface();
		ConsoleUserInterface(const ConsoleUserInterface%);

		/// <summary>
		/// Writes text centered
		/// </summary>
		/// <param name="message"></param>
		void writeCentered(System::String^ message);
	};
}