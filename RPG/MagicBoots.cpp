#include "MagicBoots.h"

using namespace Items;

MagicBoots::MagicBoots()
{
	this->Name = "MagicBoots";
	this->Stats = gcnew Statistics(0, 0, 2, 0, 1, 2, 2, 0);
}