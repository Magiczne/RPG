#pragma once

public ref class ItemNotWearableException 
	: public System::Exception
{
public:
	ItemNotWearableException() 
		: Exception("Item is not wearable!") {}
};