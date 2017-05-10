#pragma once

public ref class PlayerDeadException
	: public System::Exception
{
public:
	PlayerDeadException()
		: Exception("Player is dead!") {}
};