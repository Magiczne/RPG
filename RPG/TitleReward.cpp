#include "TitleReward.h"
#include "TitledCharacter.h"

using namespace Encounters::Rewards;

using namespace System;

TitleReward::TitleReward(String^ title)
{
	this->_title = title;
}

void TitleReward::apply(ICharacter^ character)
{
	auto titled = gcnew TitledCharacter(character, this->_title);
	character = titled;
}