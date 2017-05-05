#pragma once

namespace UI
{
	public interface class UserInterface
	{
		/// <summary>
		/// Asks the user a question with answers and gets the answer from user
		/// </summary>
		/// <param name="question">Question to ask</param>
		/// <param name="answers">Answers for the question</param>
		/// <returns>Chosen answer numer</returns>
		int askQuestion(System::String^ question, System::Collections::Generic::List<System::String^>^ answers);

		/// <summary>
		/// Shows a message for the user
		/// </summary>
		/// <param name="message">Message to show</param>
		void showMessage(System::String^ message);
	};
}