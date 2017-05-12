#include "Helmet.h"

using namespace Items;

Helmet::Helmet()
{
	this->Name = "Helmet";
	this->Stats = gcnew Statistics(0, 0, 0, 0, 5, 2, 0, 0);
}