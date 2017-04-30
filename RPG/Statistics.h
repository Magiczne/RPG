#pragma once

public ref class Statistics
{
private:
	int _hp;
	int _mana;
	int _intelligence;
	int _agility;
	int _strength;
	int _toughness;
	int _wisdom;
	int _gold;

public:
	Statistics(int hp, int mana, int intl, int agi, int str, int tgh, int wis, int gold);

	#pragma region Properties

	property int HP
	{
		int get();
		private: void set(int hp);
	}

	property int Mana
	{
		int get();
		private: void set(int mana);
	}

	property int Intelligence
	{
		int get();
		private: void set(int intelligence);
	}

	property int Agility
	{
		int get();
		private: void set(int agility);
	}

	property int Strength
	{
		int get();
		private: void set(int strength);
	}

	property int Toughness
	{
		int get();
		private: void set(int toughness);
	}

	property int Wisdom
	{
		int get();
		private: void set(int wisdom);
	}

	property int Gold
	{
		int get();
		private: void set(int gold);
	}

	#pragma endregion

	void add(Statistics^ s);
	void substract(Statistics^ s);
};