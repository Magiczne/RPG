#include "Bread.h"

using namespace Items;

Bread::Bread()
{
	this->Name = "Bread";
	this->Stats = gcnew Statistics(20, 5, 0, 0, 0, 0, 0, 0);
}