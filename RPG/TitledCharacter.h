#pragma once

#include "ICharacterDecorator.h"

public ref class TitledCharacter
	: public ICharacterDecorator
{
private:
	ICharacter^ _character;
	System::String^ _title;

public:
	TitledCharacter(ICharacter^ character, System::String^ title);

	/// <summary>
	/// Character descriptin
	/// </summary>
	property System::String^ Description
	{
		virtual System::String^ get() override;
	}
};