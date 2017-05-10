#include "Encounter.h"

using namespace Encounters;
using namespace UI;

UserInterface^ Encounter::UserInterface::get()
{
	return this->_userInterface;
}

void Encounter::UserInterface::set(UI::UserInterface^ value)
{
	this->_userInterface = value;
}