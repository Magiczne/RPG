#include "GoldReward.h"
#include "StatisticsFactory.h"

using namespace Encounters::Rewards;

GoldReward::GoldReward()
{
	this->_stats = StatisticsFactory::Empty;
}

void GoldReward::apply(ICharacter^ character)
{
	character->Stats->add(this->_stats);
}

void GoldReward::addGold(int amount)
{
	this->_stats->add(StatisticsFactory::onlyGold(amount));
}