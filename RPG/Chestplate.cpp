#include "Chestplate.h"

using namespace Items;

Chestplate::Chestplate()
{
	this->Name = "Chestplate";
	this->Stats = gcnew Statistics(0, 0, 0, 5, 0, 1, 0, 0);
}