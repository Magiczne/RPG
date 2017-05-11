#include "MadCharacter.h"

MadCharacter::MadCharacter(ICharacter^ character) 
	: IOpponent(character->getStatistics())
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