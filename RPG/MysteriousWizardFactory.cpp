#include "GiantWaspFactory.h"
#include "Character.h"

using namespace System;

Character^ GiantWaspFactory::createCharacter()
{
	auto random = gcnew Random();
	auto tgh = random->Next(1, 3);

	return gcnew Character(
		"Orc",
		gcnew Statistics(200, 150, 5, 0, 0, tgh, 4, 15))
		);
}