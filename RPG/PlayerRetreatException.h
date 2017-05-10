#pragma once

public ref class PlayerRetreatException
	: public System::Exception
{
public:
	PlayerRetreatException()
		: Exception("Player retreated!") {}
};