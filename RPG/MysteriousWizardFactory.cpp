#include "stdafx.h"
#include "MysteriousWizardFactory.h"
#include "Character.h"

using namespace System;

Character^ MysteriousWizardFactory::createCharacter()
{
	auto random = gcnew Random();
	auto tgh = random->Next(1, 3);

	return gcnew Character(
		"Mysterious Wizard",
		gcnew Statistics(200, 150, 5, 0, 0, tgh, 4, 15)
		);
}