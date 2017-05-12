#include "Game.h"

using namespace System;

int main(array<String^>^ args)
{
	auto game = gcnew Game();

	game->start();

    return 0;
}
