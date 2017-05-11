#include "IGame.h"

using namespace UI;

IUserInterface^ IGame::UserInterface::get()
{
	return this->_userInterface;
}