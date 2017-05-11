#include "IEncounter.h"

using namespace Encounters;
using namespace UI;

IUserInterface^ IEncounter::UserInterface::get()
{
	return this->_userInterface;
}

void IEncounter::UserInterface::set(UI::IUserInterface^ value)
{
	this->_userInterface = value;
}