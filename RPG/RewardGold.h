#pragma once

#include "IReward.h"

ref class RewardGold : public Encounters::Rewards::IReward
{
private:
	int _gold;

public:
	RewardGold(int gold);

	void apply(ICharacter^ character) override;
};

