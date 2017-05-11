#include "IGame.h"

using namespace UI;

IUserInterface^ IGame::UserInterface::get()
{
	return this->_userInterface;
}

void IGame::UserInterface::set(IUserInterface^ value)
{
	this->_userInterface = value;
}