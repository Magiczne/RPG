#include "ICharacterDecorator.h"

using namespace System;

ICharacterDecorator::ICharacterDecorator(ICharacter^ character)
	: ICharacter(character->Stats)
{
	this->_character = character;
}

String^ ICharacterDecorator::Description::get()
{
	return this->_character->Description;
}

Statistics^ ICharacterDecorator::Stats::get()
{
	return this->_character->Stats;
}

Equipment^ ICharacterDecorator::Eq::get()
{
	return this->_character->Eq;
}

int ICharacterDecorator::MaxHp::get()
{
	return this->_character->MaxHp;
}

int ICharacterDecorator::MaxMana::get()
{
	return this->_character->MaxMana;
}

int ICharacterDecorator::baseMeleeAttack()
{
	return this->_character->baseMeleeAttack();
}

int ICharacterDecorator::baseRangeAttack()
{
	return this->_character->baseRangeAttack();
}

int ICharacterDecorator::blockAttack()
{
	return this->_character->blockAttack();
}

void ICharacterDecorator::use(int index)
{
	this->_character->use(index);
}

bool ICharacterDecorator::wear(int index)
{
	return this->_character->wear(index);
}

bool ICharacterDecorator::unWear(int index)
{
	return this->_character->unWear(index);
}