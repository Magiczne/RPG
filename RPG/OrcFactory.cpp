#include "OrcFactory.h"
#include "Orc.h"

using namespace System;

Character^ OrcFactory::createCharacter()
{
	auto random = gcnew Random();
	auto str = random->Next(0, 10);

	return gcnew Orc(
		gcnew Statistics(
			(10 - str) * 5, 
			0, 
			0, 
			1, 
			str,
			10 - str,
			0,
			random->Next(0, 10)
		)
	);
}