#include "Apple.h"

using namespace Items;

Apple::Apple()
{
	this->Name = "Apple";
	this->Stats = gcnew Statistics(10, 0, 0, 0, 0, 0, 0, 0);
}