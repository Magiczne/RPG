#include "Game.h"

#include "ConsoleUserInterface.h"

using namespace System;
using namespace System::Collections::Generic;

int main(array<String^>^ args)
{
	auto game = gcnew Game();

	game->start();

    return 0;
}
