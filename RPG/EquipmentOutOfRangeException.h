#pragma once

namespace Exceptions
{
	public ref class EquipmentOutOfRangeException : System::Exception
	{
	public:
		EquipmentOutOfRangeException() : Exception("Brak przedmiotu w ekwipunku")
		{
		}
	};
}