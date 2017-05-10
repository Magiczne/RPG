#include "GiantWaspFactory.h"
#include "GiantWasp.h"

using namespace System;

Character^ GiantWaspFactory::createCharacter()
{
	return gcnew GiantWasp(
		gcnew Statistics(
			3 * 5, 
			0, 
			0, 
			8, 
			0, 
			3,
			0, 
			0
		)
	);
}