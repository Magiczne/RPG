#include "TitledCharacter.h"

using namespace System;

TitledCharacter::TitledCharacter(ICharacter^ character, String^ title)
	: ICharacterDecorator(character)
{
	this->_character = character;
	this->_title = title;
}

String^ TitledCharacter::Description::get()
{
	return this->_title + " " + ICharacterDecorator::Description;
}