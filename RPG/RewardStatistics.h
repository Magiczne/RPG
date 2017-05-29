#pragma once

#include "IReward.h"

ref class RewardStatistics :
	public Encounters::Rewards::IReward
{
public:
	RewardStatistics();
	void apply(ICharacter^ ch) override;
};

