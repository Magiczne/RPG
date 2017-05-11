#include "MadCharacter.h"

MadCharacter::MadCharacter(ICharacter^ character) 
	: IOpponent(character->Stats)
{
	this->_character = character;
}

int MadCharacter::baseMeleeAttack()
{
	return this->_character->baseMeleeAttack();
}

int MadCharacter::baseRangeAttack()
{
	return this->_character->baseRangeAttack();
}

int MadCharacter::blockAttack()
{
	return this->_character->blockAttack();
}