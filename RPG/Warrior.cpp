#include "Warrior.h"

using namespace System;

Warrior::Warrior(String^ desc) : Character(desc, gcnew Statistics(25, 0, 0, 2, 4, 5, 0, 0))
{
	
}