#include "GiantWaspFactory.h"
#include "Character.h"

using namespace System;

Character^ GiantWaspFactory::createCharacter()
{
	return gcnew Character(
		"Orc",
		gcnew Statistics(20, 0, 0, 8, 0, 3, 0, 0))
	);
}