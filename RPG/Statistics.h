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

	/// <summary>
	/// Health Points
	/// </summary>
	property int HP
	{
		int get();
		private: void set(int hp);
	}

	/// <summary>
	/// Mana Points
	/// </summary>
	property int Mana
	{
		int get();
		private: void set(int mana);
	}

	/// <summary>
	/// Intelligence Points
	/// </summary>
	property int Intelligence
	{
		int get();
		private: void set(int intelligence);
	}

	/// <summary>
	/// Agility Points
	/// </summary>
	property int Agility
	{
		int get();
		private: void set(int agility);
	}

	/// <summary>
	/// Strength Points
	/// </summary>
	property int Strength
	{
		int get();
		private: void set(int strength);
	}

	/// <summary>
	/// Toughness Points
	/// </summary>
	property int Toughness
	{
		int get();
		private: void set(int toughness);
	}

	/// <summary>
	/// Wisdom Points
	/// </summary>
	property int Wisdom
	{
		int get();
		private: void set(int wisdom);
	}

	/// <summary>
	/// Gold
	/// </summary>
	property int Gold
	{
		int get();
		private: void set(int gold);
	}

	#pragma endregion

	/// <summary>
	/// Adds statistics from parameter to the current object
	/// </summary>
	/// <param name="s">Other statistics object</param>
	void add(Statistics^ s);

	/// <summary>
	/// Substracts statistics from parameter to the current object
	/// </summary>
	/// <param name="s">Other statistics object</param>
	void substract(Statistics^ s);
};