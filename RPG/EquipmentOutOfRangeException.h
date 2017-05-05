#pragma once

public ref class EquipmentOutOfRangeException 
	: public System::Exception
{
public:
	EquipmentOutOfRangeException() 
		: Exception("Equipment out of range!") {}
};