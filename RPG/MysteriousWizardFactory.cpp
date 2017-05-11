#include "MysteriousWizardFactory.h"
#include "MysteriousWizard.h"

using namespace System;

ICharacter^ MysteriousWizardFactory::createCharacter()
{
	auto random = gcnew Random();
	auto intelligence = random->Next(0, 8);

	return gcnew MysteriousWizard(
		gcnew Statistics(
			(10 - intelligence) * 5,
			0,
			intelligence,
			1,
			0,
			10 - intelligence,
			0,
			random->Next(0, 10)
		)
	);
}