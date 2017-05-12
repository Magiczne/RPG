#include "IItem.h"

using namespace Items;

using namespace System;

#pragma region Getters

String^ IItem::Name::get()
{
	return this->_name;
}

int IItem::Price::get()
{
	return this->_price;
}

Statistics^ IItem::Stats::get()
{
	return this->_statistics;
}

#pragma endregion

#pragma region Setters

void IItem::Name::set(String^ value)
{
	this->_name = value;
}

void IItem::Price::set(int value)
{
	this->_price = value;
}

void IItem::Stats::set(Statistics^ value)
{
	this->_statistics = value;
}

#pragma endregion
