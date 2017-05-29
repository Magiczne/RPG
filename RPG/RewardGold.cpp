#include "RewardGold.h"
#include "StatisticsFactory.h"

RewardGold::RewardGold(int gold)
{
	this->_gold = gold;
}

void RewardGold::apply(ICharacter ^ character)
{
	//UserInterface::showMessage(TextLoader::load("messages\\reward\\gold.txt", 1));

	//UserInterface::showMessage(Convert::ToString(this->_gold) + " " + TextLoader::load("messages\\reward\\gold.txt", 2));
	
	//character->addStatistics(GoldFactory::createGold(this->_gold));

	character->Stats->add(StatisticsFactory::onlyGold(this->_gold));
}